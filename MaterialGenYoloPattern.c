#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * A : Material.AIR, S : Material.STONE, W : Material.WOOD
 */

 typedef struct Material Material;

 struct Material {

    char AIR;
    char STONE;
    char WOOD;
 };

void genPattern(int size, int sizeY);

int main() {

    genPattern(12, 12);

    return 0;
}

void genPattern(int sizeX, int sizeY) {

    Material m;
    m.AIR = ' ';
    m.STONE = 'S';
    m.WOOD = 'W';

    srand(time (NULL));

    int ord = (rand() % sizeX) + 1;    /* Ordonnées */
    int abs = (rand() % sizeY) + 1;    /* Abscisses */
    int choice = (rand() % 100) + 1;

    int i;
    for (i = 0; i < ord; i++) {

        if ((choice % 2) == 0)
            printf("%c", m.STONE);
        else
            printf("%c%c", m.WOOD, m.WOOD ? choice % 2 == 0 : choice % 2 != 0);

        int ii;
        for (ii = 0; ii < abs; ii++) {

            if ((choice % 2) == 0)
                printf("%c", m.WOOD);
            else
                printf("%c%c", m.STONE, m.STONE ? (choice % 2) == 0 : (choice % 2) != 0);
        }
        printf("%c", m.AIR);
    }
}
