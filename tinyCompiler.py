# https://austinhenley.com/blog/teenytinycompiler1.html 
# Objectifs : 
#   - suivre le tutoriel
#   - modifier le fonctionnement pour commencer à comprendre
#   - ajouter quelques fonctionnalités (fonction, tableau, lecture/écriture fichier...)
# 

import sys
import enum

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


def main():

    input = """+-*/>> 5 6.22 7 8 ==!= # je suis un 545 c"ommentaire"
    + - "Un string !  123546 87 554 s+" /=
    +- \"This is a string\" 55 # This is a comment!\n */
    foo THEN IF ELSE ENDIF enDIF"""
    
    lexer = Lexer(input)
    token = lexer.getToken()

    while token.kind != TokenType.EOF:

        print(token.kind)
        token = lexer.getToken()

main()
