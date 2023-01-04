#include <stdio.h>
#include <stdlib.h>

void fail(int n, int c) {

    int result = ((c + 1) % (2 * n));
    printf("%d ", result);
}

int main() {

    fail(40, 10);
    fail(60, 10);
    fail(80, 10);

    /* Returned value : 11 11 11 */

    return 0;
}
