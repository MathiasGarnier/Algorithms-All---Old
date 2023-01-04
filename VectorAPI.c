#include <stdio.h>
#include <stdlib.h>
#include "VectorAPI.h"

int main() {

    Vector                    v;

    v.length            =     8;
    v.direction[0]      =   'A';
    v.direction[1]      =   'B';
    v.way[0]            =   'A';
    v.way[1]            =   'B';

    Vector                   v1;

    v1.length           =     8;
    v1.direction[0]     =   'A';
    v1.direction[1]     =   'B';
    v1.way[0]           =   'A';
    v1.way[1]           =   'B';

    vectorCompare(v, v1);

    //YOLO PATE A L'EAU
    return 0;
}
