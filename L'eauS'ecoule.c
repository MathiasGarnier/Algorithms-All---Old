#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Material Material;

struct Material {

    char WATER;
};

void wateringggggggg(int floor);

int main() {

    wateringggggggg(7);
    return 0;
}

void wateringggggggg(int floor) {

    Material m;
    m.WATER = 'W';

    printf("L\'eau secoule fiouuuuu\n");

    srand(time (NULL));
    int choice = (rand() % 100) + 1;
    int i;
    for (i = floor; i > 0; i--)
        printf("%c\n", m.WATER);
}
