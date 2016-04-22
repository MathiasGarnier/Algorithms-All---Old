#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int x, xx, xxx, y, yy, yyy;
    int n, nn;

    srand (time (NULL));
   nn = rand() % 10;

    for(n = 0; n < nn; n++)
    {
        for(x = 0; x < 9; x++)
        {
            x += 1;
            for(xx = 0; xx < x; xx++)
            {
                for(y = 0; y < 9; y++)
                {
                    y += 2;
                    for(yy = 0; yy < y; yy++)
                    {
                        printf(" ");
                    }
                    for (yyy = 0; yyy < ((2 * y) - 1); yyy++)
                    {
                        printf ("*");
                    }
                }

                printf(" ");
            }
            for (xxx = 0; xxx < ((2 * x + 1) - 1); xxx++)
            {
                printf ("*");
            }
            printf("\n ");
        }
        printf(" ");
    }
    return 0;
}
