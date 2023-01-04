#include <iostream>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iterator>

std::vector<int> genParking(int l, int L);
int getNbPlaceLibre();

int main() {

    std::vector<int> l = genParking(10, 15);

    return 0;
}

std::vector<int> genParking(int l, int L) {

    srand(time(NULL));

    std::vector<int> vector;

    for (int i = 0; i < l; ++i) {

        for (int ii = 0; ii < L; ++ii) {

            vector.push_back(rand() % 4);
            std::cout << vector[(i & ii) + 1];
        }
        std::cout << std::endl;
    }
}

//Display : 1468025611111111111111 at first line, every rebuild of program that's isn't the same sequence.
