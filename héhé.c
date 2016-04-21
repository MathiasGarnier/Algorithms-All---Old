#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x;
    while(x)
    {
    scanf("%d", &x);
    if(x >= 1)
        printf("Hehe\n");
    else if(x == 0)
        printf("NUL\n");
    else
        printf("BOUM\n");
    }
    return 0;
}
