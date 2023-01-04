#include <iostream>

int main () {

    for (int i = 0; i < 6; i++) {
        int test = ((0x0000F ^ i) & 0x000A) << 2;
        std::cout << test << std::endl;

        /*
         * Returned value:
         *
         *               40
         *               40
         *               32
         *               32
         *               40
         *               40
         */
    }

    system("pause");
    return 0;
}
