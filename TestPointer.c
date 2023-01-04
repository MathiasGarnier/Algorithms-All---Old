#include <stdio.h>
#include <stdlib.h>

int main() {

    int a = 100;
    int b = 50;

    int *pointeurA = &a;
    int *pointeurB = &b;

    printf("%d - %p\n",*pointeurA, pointeurA);
    printf("%p\n", &a);

    *pointeurA += 15;
    pointeurA = &pointeurB;

    printf("%d", *pointeurA);
    printf("%d - %p\n",*pointeurA, pointeurA);

    return 0;
}
