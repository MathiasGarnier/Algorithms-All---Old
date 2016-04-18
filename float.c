#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, s;
    printf ("Valeur de a :\n");
    scanf ("%f", &a);
    printf ("Valeur de b :\n");
    scanf ("%f", &b);
    s = a + b;
    printf("Valeur de a + b : %.2f", s);
    getchar();
    return 0;
}
