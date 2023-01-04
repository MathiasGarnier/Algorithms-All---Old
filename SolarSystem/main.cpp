#include <iostream>
#include "Planet.h"
#include "Satellite.h"

int main() {

	Planet Mercury = Planet("mercury", 70000000, 2440, 330);
	Planet Venus = Planet("venus", 108002000, 6052,4868);
	Planet Earth = Planet("earth", 149006000, 6378, 5973);
	Planet Mars = Planet("mars", 227009000, 3397, 641);
	Planet Jupiter = Planet("jupiter", 778005000, 71492, 1898600);
	Planet Saturn = Planet("saturn", 1429000000, 60268, 568460);
	Planet Uranus = Planet("uranus", 2871000000, 25559, 86832);
	Planet Neptune = Planet("neptune", 4498000000, 24766, 102430);


	Satellite s = Satellite("mercury", 70000000, 2440, 330);

	std::cout << std::boolalpha << Mercury.compare<Satellite>(s) << " ";
	std::cout << std::boolalpha << Mercury.compare<Planet>(s);
	return 0;
}