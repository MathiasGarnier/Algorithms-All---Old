#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time (NULL));

    int nb = (rand() % 100) + 1;

    int uNB = -1;


    do {

        scanf("%d", &uNB);

        if (uNB > nb) printf("<");
        else if (uNB < nb) printf(">");
        else printf("=");
        //YOLO
    } while (uNB != nb);

    return 0;
}
