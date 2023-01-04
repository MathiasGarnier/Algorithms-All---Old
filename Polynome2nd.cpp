#include <iostream>
#include <cstdio>
#include <cmath>

int main() {

    double a(0.), b(0.), c(0.);
    double delta(0.);
    double resultat(0.);

    std::cout << "A (non nul) : ";
    scanf("%lf", &a);

    std::cout << "B : ";
    scanf("%lf", &b);

    std::cout << "C : ";
    scanf("%f", &c);

    delta = b * b - 4 * a * c;

    if (delta < 0) std::cout << "Pas de solution reelles.";
    else if (delta == 0) resultat = -b / 2 * a;
    else resultat = (-b + sqrt(delta)) / 2 * a;

    std::cout << resultat;
    
    return 0;
}
