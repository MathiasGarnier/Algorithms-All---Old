#include <iostream>
#include <time.h>

int main () {

    int s[randomize()];
    std::cout << s[0];
    //Rebuild and rerun the program many times.
    
}

unsigned int randomize() {

    srand(time(NULL));
    unsigned int randomNumber = (rand() % 9);

    return randomNumber;
}
