# https://austinhenley.com/blog/teenytinycompiler1.html 
# Objectifs : 
#   - suivre le tutoriel
#   - modifier le fonctionnement pour commencer à comprendre
#   - ajouter quelques fonctionnalités (fonction, tableau, lecture/écriture fichier...)
#   - modifier les règles de grammaire pour faire un mini-assembleur (et comparer avec un vrai asm)
#   - on ne peut pas redéfinir une même variable avec LET, écrire manière de rédéfinir (vérif existence label + update valeur)

# Liste reprise de la partie trois du tutoriel 
# [ ] Gérer un système d'expressions plus compliqué (parenthèses, priorité...)
# [ ] ELSE IF & ELSE
# [ ] SWITCH & CASE
# [ ] FOR (utiliser un GOTO ?)
# [ ] Opérateurs logiques
# [ ] Améliorer les messages d'erreur / avertissement du compilateur
# [ ] Plusieurs fichiers qui s'imbriquent
# [ ] FUNCTION & LAMBDA
# [ ] D'autres types primitifs (string, int, bool, ...; auto)
# [ ] tableaux
# [ ] Sorte de système de classe / structure

# On n'y est pas encore aux optimisations compilateurs.
# Je vais juste essayer de voir comment ça se passe sur d'autres projets avant d'aller plus loin. Et va falloir penser à abandonner le Python et passer au C / C++ ou ASM ...

# Le truc chiant est que c'est plus un "traducteur" qu'un réel compilateur ?
# "our compiler will be platform independent without dealing with assembly code or complex compiler frameworks."
# Gné...
# Comment faire autrement ?

import sys
import enum

global DEBUG
DEBUG = True

class TokenType(enum.Enum):

	EOF = -1
	NEWLINE = 0
	NUMBER = 1
	IDENT = 2
	STRING = 3

	# Mots clefs
	LABEL = 101
	GOTO = 102
	PRINT = 103
	INPUT = 104
	LET = 105
	IF = 106
	THEN = 107
	ENDIF = 108
	WHILE = 109
	REPEAT = 110
	ENDWHILE = 111

	# Opérateurs
	EQ = 201  
	PLUS = 202
	MINUS = 203
	ASTERISK = 204
	SLASH = 205
	EQEQ = 206
	NOTEQ = 207
	LT = 208
	LTEQ = 209
	GT = 210
	GTEQ = 211


class Token:

    def __init__(self, tokenText, tokenKind):
        
        self.text = tokenText
        self.kind = tokenKind # Type

    @staticmethod
    def checkIfKeyword(token):

        for kind in TokenType: 
            
            if kind.name == token and \
               kind.value >= 100 and \
               kind.value < 200:
               return kind

        return None


class Lexer:

    """
        Opérateurs : +, -, *, /, =, ==, !=, >, <, >=, <=.
        Chaînes (String).
        Nombres (entiers ou décimaux).
        Identifieurs (variables).
        Mots clefs (LABEL, GOTO, PRINT, INPUT, LET, IF, THEN, ENDIF, WHILE, REPEAT, ENDWHILE).
    """

    # @TODO : 
    #   - commentaire (ajouter \) : # sjsjsjs \
    #                                 sksbsjkbnzs
    #   - améliorer le découpage du texte (optimiser un petit peu)
    #       (pour les variables, nombres et strings)
    #   - ajouter un ELSE, ENDELSE
    #   - ajouter un SWITCH case...

    def __init__(self, input):

        self.source = input + "\n"
        self.currentChar = ""
        self.currentPos = -1
        self.nextChar()

    # Regarder le caractère suivant.
    def nextChar(self):

        self.currentPos += 1

        if self.currentPos >= len(self.source):
            self.currentChar = "\0" # End Of File
        else:
            self.currentChar = self.source[self.currentPos]

    # Regarder le caractère suivant sans modifier le pointeur.
    def peek(self):

        if self.currentPos + 1 >= len(self.source):
            return "\0"
        
        return self.source[self.currentPos + 1]
        

    # Token invalide trouvé, 
    # Renvoyer message d'erreur et stop.
    def abort(self, message):
        
        sys.exit("Erreur du lexer. " + message)

    # Sauter les espacements (sauf les nouvelles lignes).
    # Utilisé pour découper le code en morceaux.
    def skipWhitespace(self):
        
        while self.currentChar == " " or \
              self.currentChar == "\t" or \
              self.currentChar == "r":

              self.nextChar()

    # Sauter les commentaires.
    def skipComment(self):
        
        if self.currentChar == "#":
            while self.currentChar != "\n":
                self.nextChar()

    # Retourner le token suivant.
    # "Nourriture" du lexer.
    def getToken(self):
        
        self.skipWhitespace()
        self.skipComment()

        token = None

        # Opérateurs arithmétiques
        if self.currentChar == "+":
            token = Token("+", TokenType.PLUS)

        elif self.currentChar == "-":
            token = Token("-", TokenType.MINUS)

        elif self.currentChar == "*":
            token = Token("*", TokenType.ASTERISK)
        
        elif self.currentChar == "/":
            token = Token("/", TokenType.SLASH)

        elif self.currentChar == "\n":
            token = Token("\n", TokenType.NEWLINE)

        elif self.currentChar == "=":
            if self.peek() == "=":
                self.nextChar()
                token = Token("==", TokenType.EQEQ)
            else:
                token = Token("=", TokenType.EQ)

        elif self.currentChar == ">":
            if self.peek() == "=":
                self.nextChar()
                token = Token(">=", TokenType.GTEQ)
            else:
                token = Token(">", TokenType.GT)

        elif self.currentChar == "<":
            if self.peek() == "=":
                self.nextChar()
                token = Token("<=", TokenType.LTEQ)
            else:
                token = Token("<", TokenType.LT)

        elif self.currentChar == "!":
            if self.peek() == "=":
                self.nextChar()
                token = Token("!=", TokenType.NOTEQ)
            else:
                self.abort("Token \"!=\" attendu.")

        # String
        elif self.currentChar == "\"":
            self.nextChar()
            strBegin = self.currentPos

            while self.currentChar != "\"":
                if self.currentChar == '\r' or self.currentChar == '\n' or self.currentChar == '\t' or self.currentChar == '\\' or self.currentChar == '%':
                    self.abort("Caractère illégal dans le string : " + self.currentChar)                
                self.nextChar()

            strText = self.source[strBegin : self.currentPos]
            token = Token(strText, TokenType.STRING)

        # Nombre (entier ou à virgule)
        elif self.currentChar.isdigit(): 

            numBegin = self.currentPos

            while self.peek().isdigit():
                self.nextChar()
            if self.peek() == ".":
                self.nextChar()

                if not self.peek().isdigit():
                    self.abort("Ce caractère aurait dû être un nombre : " + self.currentChar)
                while self.peek().isdigit():
                    self.nextChar()

            numText = self.source[numBegin : self.currentPos + 1] # + 1 pour obtenir le guillemet final
            token = Token(numText, TokenType.NUMBER)

        # Identifieur et mots clefs
        elif self.currentChar.isalpha():

            keywBegin = self.currentPos

            while self.peek().isalnum():
                self.nextChar()

            alphaText = self.source[keywBegin : self.currentPos + 1]
            keyword = Token.checkIfKeyword(alphaText)

            # Identifieur
            if keyword == None:
                token = Token(alphaText, TokenType.IDENT)
            # MOT-CLEF
            else:
                token = Token(alphaText, keyword)

        # End Of File
        elif self.currentChar == "\0":
            token = Token("", TokenType.EOF)
        
        # Token inconnu
        else:
            self.abort("Token inconnu : " + self.currentChar)
			
        self.nextChar()
        return token

class Parser:

    """
        Vérifier que la syntaxe soit correcte.
        Prend en entrée suite de Tokens.
        Retourne un arbre syntaxique.

        Correspondence bijective entre les règles de grammaire et l'implémentation.
    """

    def __init__(self, lexer, emitter):
        
        self.lexer = lexer
        self.emitter = emitter

        self.symbols = set()
        self.labelsDeclared = set()
        self.labelsGotoed = set()

        self.currentToken = None
        self.peekToken = None

        self.nextToken()    # Appeler deux fois pour initialiser le présent
        self.nextToken()    # et le suivant.

    # Renvoyer True si c'est le bon token.
    def checkToken(self, kind):
        
        return kind == self.currentToken.kind

    # Renvoyer True si le prochain token est le bon token.
    # Permet (avec checkToken) de savoir quelle règle syntaxique
    # doit être appliquée en fonction du présent token et du suivant.
    def checkPeek(self, kind):
        
        return kind == self.peekToken.kind

    # Attend en entrée un token spécifique sinon retourne une erreur.
    def match(self, kind):
        
        if not self.checkToken(kind):
            self.abort("Le token suivant \"" + kind.name + "\" était attendu (et non \"" + self.currentToken.kind.name + "\").")
        
        self.nextToken()

    # Passe au token suivant.
    def nextToken(self):

        self.currentToken = self.peekToken
        self.peekToken = self.lexer.getToken()

    # Arrêt du programme.
    def abort(self, message):
        
        sys.exit("Erreur lors du parsing. " + message)

    """
        Pour chaque règle de grammaire, on a une fonction.
    """

    # Nouvelle ligne
    def nl(self):

        if DEBUG: print("NEWLINE")

        self.match(TokenType.NEWLINE)

        while self.checkToken(TokenType.NEWLINE):
            self.nextToken()

    # Opérateur primaire (nombre ou identifieur)
    def primary(self):

        if DEBUG: print("PRIMAIRE (" + self.currentToken.text + ")")

        if self.checkToken(TokenType.NUMBER):

            self.emitter.emit(self.currentToken.text)            
            self.nextToken()

        elif self.checkToken(TokenType.IDENT):

            if self.currentToken.text not in self.symbols:
                self.abort("Variable (" + self.currentToken.text + ") utilisée mais non déclarée")
            
            self.emitter.emit(self.currentToken.text)            
            self.nextToken()

        else:
            
            self.abort("Token non attendu : " + self.currentToken.text + ".")

    # Opérateur binaire (plus ou moins primaires)
    def unary(self):

        if DEBUG: print("UNAIRE")

        if self.checkToken(TokenType.PLUS) or self.checkToken(TokenType.MINUS):

            self.emitter.emit(self.currentToken.text)
            self.nextToken()

        self.primary()

    # Opérateur arithmétique (fois ou divisé)
    def term(self):

        if DEBUG: print("TERME")
        self.unary()

        while self.checkToken(TokenType.ASTERISK) or self.checkToken(TokenType.SLASH):
            
            self.emitter.emit(self.currentToken.text)
            self.nextToken()
            self.unary()

    # Opérateur arithmétique (plus ou moins)
    def expression(self):

        if DEBUG: print("EXPRESSION")
        self.term()

        while self.checkToken(TokenType.PLUS) or self.checkToken(TokenType.MINUS):
            
            self.emitter.emit(self.currentToken.text)
            self.nextToken()
            self.term()

    # Est-ce un opérateur de comparaison ?
    def isComparisonOperator(self):

         return self.checkToken(TokenType.GT) or self.checkToken(TokenType.GTEQ) or self.checkToken(TokenType.LT) or self.checkToken(TokenType.LTEQ) or self.checkToken(TokenType.EQEQ) or self.checkToken(TokenType.NOTEQ)

    # Comparaison sur les opérateurs arithmétiques
    def comparison(self):
        
        if DEBUG: print("COMPARAISON")

        self.expression()

        if self.isComparisonOperator():
            
            self.emitter.emit(" " + self.currentToken.text + " ")
            self.nextToken()
            self.expression()
        
        else:

            self.abort("Opérateur de comparaison attendu : " + self.currentToken.text + ".")

        while self.isComparisonOperator():

            self.emitter.emit(self.currentToken.text)
            self.nextToken()
            self.expression()

    def statement(self):
        
        # PRINT
        if self.checkToken(TokenType.PRINT):

            if DEBUG: print("STATEMENT-PRINT")
            self.nextToken()

            if self.checkToken(TokenType.STRING):
                self.emitter.emitLine("\tprintf(\"" + self.currentToken.text + "\");")
                self.nextToken()
            else:
                self.emitter.emit("\tprintf(\"%.2f\", (float) (")
                self.expression()
                self.emitter.emitLine("));")

        # IF ... THEN ... ENDIF
        elif self.checkToken(TokenType.IF):

            if DEBUG: print("STATEMENT-IF")
            self.nextToken()
            self.emitter.emit("\tif(")
            self.comparison()
            
            self.match(TokenType.THEN)
            self.nl()
            self.emitter.emitLine(") {")

            # Expression dans le STATEMENT-IF
            while not self.checkToken(TokenType.ENDIF):
                self.statement()

            self.match(TokenType.ENDIF)
            self.emitter.emitLine("\t}")

        # WHILE ... REPEAT ... ENDWHILE
        elif self.checkToken(TokenType.WHILE):

            if DEBUG: print("STATEMENT-WHILE")
            self.nextToken()
            self.emitter.emit("\twhile(")
            self.comparison()

            self.match(TokenType.REPEAT)
            self.nl()
            self.emitter.emitLine(") {")

            # Expression dans le STATEMENT-WHILE
            while not self.checkToken(TokenType.ENDWHILE):
                self.statement()

            self.match(TokenType.ENDWHILE)
            self.emitter.emitLine("\t}")

        # LABEL
        elif self.checkToken(TokenType.LABEL):
            
            if DEBUG: print("STATEMENT-LABEL")
            self.nextToken()

            # Vérifier que le label n'existe pas déjà
            if self.currentToken.text in self.labelsDeclared:
                self.abort("Le label \"" + self.currentToken.text + "\" existe déjà.")
            
            self.labelsDeclared.add(self.currentToken.text)

            self.emitter.emitLine("\t" + self.currentToken.text + ":")  # pourquoi ":" ?
            self.match(TokenType.IDENT)

        # GOTO
        elif self.checkToken(TokenType.GOTO):

            if DEBUG: print("STATEMENT-GOTO")
            self.nextToken()

            # Pas besoin de vérifier si le label goto existe déjà.
            self.labelsGotoed.add(self.currentToken.text)
            self.emitter.emitLine("\tgoto " + self.currentToken.text + ";")
            self.match(TokenType.IDENT)

        # LET ... = ...
        elif self.checkToken(TokenType.LET):

            if DEBUG: print("STATEMENT-LET")
            self.nextToken()

            if self.currentToken.text not in self.symbols:
                self.symbols.add(self.currentToken.text)
                self.emitter.headerLine("\tfloat " + self.currentToken.text + ";")

            self.emitter.emit("\t" + self.currentToken.text + " = ")
            self.match(TokenType.IDENT)
            self.match(TokenType.EQ)
            self.expression()
            self.emitter.emitLine(";")

        # INPUT
        elif self.checkToken(TokenType.INPUT):

            if DEBUG: print("STATEMENT-INPUT")
            self.nextToken()

            if self.currentToken.text not in self.symbols:
                self.symbols.add(self.currentToken.text)
                self.emitter.headerLine("\tfloat " + self.currentToken.text + ";")

            self.emitter.emitLine("\tif(0 == scanf(\"%" + "f\", &" + self.currentToken.text + ")) {")
            self.emitter.emitLine("\t" + self.currentToken.text + " = 0;")
            self.emitter.emit("\tscanf(\"%")
            self.emitter.emitLine("*s\");")
            self.emitter.emitLine("\t}")
            self.match(TokenType.IDENT)

        else:
            self.abort("Expression invalide : " + self.currentToken.text + " (" + self.currentToken.kind.name + ").")
        
        self.nl()

    def start(self):
        
        self.emitter.headerLine("#include <stdio.h>")
        self.emitter.headerLine("")
        self.emitter.headerLine("int main(void) {")
        self.emitter.headerLine("")
        
        while self.checkToken(TokenType.NEWLINE):
            self.nextToken()

        while not self.checkToken(TokenType.EOF):
            self.statement()

        self.emitter.emitLine("\treturn 0;")
        self.emitter.emitLine("}")
        
        for label in self.labelsGotoed:
            if label not in self.labelsDeclared:
                self.abort("Le label (GOTO) : " + label + " n'a pas été déclaré.")

class Emitter:
    
    """
        Ne sert qu'à des manipulations de String.
        Plus une interface pour se simplifier la vie qu'autre chose.
    """

    def __init__(self, fullPath):
        
        self.fullPath = fullPath

        self.header = ""
        self.code = ""

    def emit(self, code):

        self.code += code

    def emitLine(self, code):

        self.code += code + "\n"

    def headerLine(self, code):

        self.header += code + "\n"

    def writeFile(self):

        with open(self.fullPath, "w") as outputFile:
            outputFile.write(self.header + self.code)

def main():

    PATH = "C:\\Users\\mathi\\Onedrive\\Bureau\\phys\\TinyComp\\"

    if len(sys.argv) != 2:
        sys.exit("Erreur: TinyComp 1 a besoin d'un fichier à compiler.")
    
    with open(sys.argv[1], 'r') as input_file:

        input = input_file.read()
    
        lexer = Lexer(input)
        emitter = Emitter("out.c")
        parser = Parser(lexer, emitter)

        parser.start()
        emitter.writeFile()

main()
