#include <stdio.h>
#include <stdlib.h>
//#include <math.h> Be patient ;)

int main() {

    int     first   =   0;
    int     second  =   0;
    int     result  =   0;
    char    signe;

    scanf("%d", &first);
    scanf("%c", &signe);
    scanf("%d", &second);

    //You can make 66*66
    
    switch (signe) {

    case '+':
        result = first + second;
        printf("%d", result);
        break;
    case '-':
        result = first - second;
        printf("%d", result);
        break;
    case '*':
        result = first * second;
        printf("%d", result);
        break;
    case '/':
        result = first / second;
        printf("%d", result);
        break;

    default:
        printf("Veuillez re-essayer.");
        break;
    }

    return 0;
}
