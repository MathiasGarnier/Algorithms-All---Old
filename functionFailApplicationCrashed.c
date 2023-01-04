#include <stdio.h>
#include <stdlib.h>

void fail(int n, int c) {

    int result = ((c + 1) % (2 * n));
    printf("%d ", result);
}

int main() {

    int i;
    for (i = 0; i < 1; i++)
        fail(i, i);
        //Application Crashed  YEAHHHHH :joke:

    return 0;
}
