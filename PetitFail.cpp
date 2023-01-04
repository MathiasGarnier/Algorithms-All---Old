#include <iostream>

#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <sstream>

#include <algorithm>

#define nn 42 /* Valeur globale à changer pour faire varier le résultat */

int nbFois(int n);
int getDeciInt(int n);
int decimalToBinary(int n);
void toUuBit();

int main() {

    toUuBit();
}

int nbFois(int n) {

    int num = n;
    int total = 0;

    int i = 0;

	while (num > 0) {

		total = num % 2;
		num /= 2;

		i++;

        if (num < 0)
            continue;
    }
    return i;

}


int decimalToBinary(int n) {

    int num = n;
    int total = 0;

	while (num > 0) {

		total = num % 2;
		num /= 2;

        std::cout << total << " ";
    }
}

void toUuBit() {

    int num = decimalToBinary(nn);

    std::stringstream oss;
    oss << num;

    std::string nS = oss.str();

    std::replace(nS.begin(), nS.end(), ' ', '\0'); //Donc : "010101" par exemple.

    for (int i = 0; i < nbFois(nn) + 1; i++) {

        //char cNS = nS[i];

        if (nS[i] == '0'){
            std::cout << "001\n";
        }

        else if (nS[i] == '1')
            std::cout << "00-1\n";

        else
            std::cout << "NOPE ";
    }
}
