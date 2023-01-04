#include <iostream>
#include <cstdio>

int main() {

    double iG[] = {-1, -0.5, 0, 0.5, 1};
    double x;

    scanf("%lf", &x);

    for (int i = 0; i < 5; i++) {

        if (iG[i] == x) {

            std::cout << "OUI";
            return 0;
        }
        else {

            std::cout << "NOPE";
            return 0;
        }
    }
    return 0;
}
