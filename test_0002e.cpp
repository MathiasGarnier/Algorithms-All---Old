#include <iostream>

int main () {

    for (int i = 0; i < 6; i++) {
        int test = 0x00006 ^i;
        std::cout << test << std::endl;
        /*
         * Returned value :
         *                  6
         *                  7
         *                  4
         *                  5
         *                  2
         *                  3
         */
    }

    system("pause");
    return 0;
}
