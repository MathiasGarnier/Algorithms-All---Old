#include <stdio.h>
#include <stdlib.h>

/* C is beautiful ! */

int main(int argc, char const *argv[]) {

  char userName[100] = "None";

  printf("Bonjour ! Quel est votre nom ? \n");

  scanf("%s", userName);

  printf("Bienvenue %s !\n", userName);
  return 0;
}
