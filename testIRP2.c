#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct IRPC_Var { 
    
    int fun_number;
    char* var_name[][80];
};

struct IRPC_Var program = {0, {}};

#define is_function_found(function)  bool found = false; \
                                     for(int i = 0; i < program.fun_number + 1; i++) {\
                                        if (strstr(program.var_name[i], function) != NULL) {\
                                            found = true;\
                                        }\
                                     }

#define get_name(var) #var


#define __PROVIDER__(typefun, function) typefun function() {\
                                            char* function_name = get_name(function);\
                                            is_function_found(function_name)\
                                            if (!found) {\
                                                program.fun_number += 1;\
                                                strcat(program.var_name[program.fun_number - 1], function_name);}\
                                        
#define __RETURN__(var) return var; }

__PROVIDER__( char*, text )

    char* val = "Je suis un texte";
    
    __RETURN__(val)


__PROVIDER__( char*, unAutreText )

    char* val = "Je suis un autre texte";
    
    __RETURN__(val)

__PROVIDER__( char*, unAutreTexte )

    char* val = "Je suis un autre textFOIHGEDIOe";
    
    __RETURN__(val)



int main() {
    
    char* s1 = text();
    char* s2 = text();
    char* s3 = unAutreText();
    char* s4 = unAutreText();
    char* s5 = unAutreText();
    char* s6 = unAutreTexte();

    printf("\nNombre de variables : %d", program.fun_number);
    for (int i = 0; i < program.fun_number; i++) {
        printf("\nNom de la variable numéro %d : %s", i, program.var_name[i]);
    }

    return 0;
}
