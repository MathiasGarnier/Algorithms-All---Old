#include <stdio.h>
#include <stdlib.h>   // sert pour les fonctions srand et rand
#include <time.h>

int main() {

    int nb, x;

    srand (time (NULL));
    nb = rand() % 100;

    printf("Entrez un nombre : ");
    scanf("%d", &x);

    while(x != nb)
    {
        if(x > nb)
        {
            printf("<");
            scanf("%d", &x);
        } else if(x < nb)
        {
            printf(">");
            scanf("%d", &x);
        } else {
            break;
        }
    }

    return 0;
}
