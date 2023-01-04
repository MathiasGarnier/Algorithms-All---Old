#include <stdio.h>
#include <stdlib.h>

/*

0:  add             (+ 1 2)
1:  sub             (- 2 1)
2:  mul             (* 2 2)
3:  div             (/ 3 2)
4:  mod             (% 12 3)
*/

int fakeParse();

int main() {

    /* Example : (+ 5 7) */
    printf("%d", fakeParse());
    return 0;
}

int fakeParse() {

    int a, b;
    char instruction, delimitS, delimitE;       /* ( && ) */
    /* int instr = atoi(instruction); */

    scanf("%c", &delimitS);
    scanf("%c", &instruction);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%c", &delimitE);

    switch (instruction) {

    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    case '%':
        return a % b;
        break;
    default:
        printf("Try other instruction");
        break;
    }
}
