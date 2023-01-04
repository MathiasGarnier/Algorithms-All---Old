#include <iostream>

#include <stdlib.h>
#include <stdio.h>

#include <math.h>
#include <time.h>

#define LIFE_UNIVERSE_AND_THE_REST 42

int genH(int n);

int main() {

    std::cout << genH(LIFE_UNIVERSE_AND_THE_REST);
}


int genH(int n) {

    srand(time(NULL));

    int pT = pow(2, 16);
    int pTE = pow(10, 5);

    int rI = rand() % (((pTE / pT) - pTE % pT) + n);

    int hT = (pT ^ (2 * (pTE - pT)));

    int hS = hT | rI;

    return hS;
}
