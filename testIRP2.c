#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct IRPC_Var { 
    
    int fun_number;
    char* var_name[][80];
};

struct IRPC_Var program = {0, {}};

#define get_name(var) #var
#define not_already_definedFun(function) strstr(program.var_name, function) == NULL

#define __PROVIDER__(typefun, function) typefun function() {\
                                            char* function_name = get_name(function);\
                                            if (not_already_definedFun(function_name)) {\
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

    char* val = "Je suis un autre texte";
    
    __RETURN__(val)



int main() {
    
    printf("%s", text());
    printf("%s\n", unAutreText());
    printf("%s\n", unAutreText());
    printf("%s\n", unAutreText());
    printf("%s\n", unAutreTexte());

    printf("\nNombre de variables : %d", program.fun_number);
    for (int i = 0; i < program.fun_number; i++) {
        printf("\nNom de la variable numéro %d : %s", program.fun_number, program.var_name[i]);
    }

    return 0;
}
