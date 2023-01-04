#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * A : Material.AIR, S : Material.STONE, W : Material.WOOD
 */

 typedef struct Material Material;

 struct Material {

    char NULL_MATERIAL;
    char AIR;
    char STONE;
    char WOOD;
 };

int main() {

    Material m;
    m.NULL_MATERIAL = ' ';
    m.AIR = 'A';
    m.STONE = 'S';
    m.WOOD = 'W';

    int i;
    for (i = 0; i < 12; i++)
        printf("%c", m.AIR);

    int ii;
    for (ii = 0; ii < 12; ii++)
        printf("%c\n", m.NULL_MATERIAL);

    int iii;
    for (iii = 0; iii < 12; iii++) {

        srand(time (NULL));

        int randomNum = (rand() % 100) + 1;
        if ((randomNum % 2) == 0)
            printf("%c", m.STONE);
        else
            printf("%c", m.WOOD);
    }

    return 0;
}
