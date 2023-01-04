#include <iostream>
#include <time.h>
#include <array>


int yoloRandomGeneration(int n, int m);

int main () {
    
    std::cout << yoloRandomGeneration(9, 9);
}

int yoloRandomGeneration(int n, int m) {

    srand(time(NULL));

   std::array<int, 30> N { {(rand() %10), (rand() %10), (rand() %10)} };
}
