#include <iostream>

#include <stdlib.h>
#include <stdio.h>

#define mul *
#define div /

double t(double time); //En secondes

int main() {

    double seconds = 6;
    std::cout << t(seconds mul 60 mul 24 mul 7);

    return 0;
}

double t(double time) { //En secondes

    double s = time;
    double m = s div 60; //Une heure
    double h = m div 24; //Une journée
    double w = h div 7;  //Une semaine

    return w;
}
