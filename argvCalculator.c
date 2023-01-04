#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL) {

    printf("You forget at least one argument.\n");
    printf("State : %d\n", argc);
  } else {

    int a = strtod(argv[1], NULL);
    int b = strtod(argv[3], NULL);

    switch (argv[2][0]) {

    int result;

      case '-':

        result = a - b;
        printf("%d\n", result);
        break;
      case '+':

        result = a + b;
        printf("%d\n", result);
        break;
      case 'x':

        /* Why '*' -> operator return '2' ? goto jmp */
        /* Owing to '*' -> operator return '2', I must use 'x' operator lolilol*/
        result = a * b;
        printf("%d\n", result);
        break;
      case '/':

        result = a / b;
        printf("%d\n", result);
        break;
      default:

        /* jmp: */
        printf("Il y a un probleme avec votre operateur(-> %c).\n", argv[2][0]);
        break;
    }
  }
  return 0;
}
