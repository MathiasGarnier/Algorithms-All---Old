#include <iostream>
#include "Object/Key.h"
#include "Object/Place.h"
#include "Object/FileConfigurator.h"

int main() {

	//Key k("jean louis", 10, Place("garden_of_sir", true));

	//std::cout << k.getActionRange() << std::endl << k.getKeyOwner() << std::endl;

	//k.setKeyOwner("quelqu'un d'autre");
	//k.setActionRange(k.getActionRange() + 2);

	//std::cout << k.getActionRange() << std::endl << k.getKeyOwner() << std::endl;

	//k.getKeyFor();

	//k.setKeyFor(Place("garden", true));

	//Place p("garden", false);

	//std::cout << p.getName() << " ";
	//std::cout << std::boolalpha << p.isPlaceState();

	//Place pl("garden");

	//std::cout << pl.getName() << " ";
	//pl.setPlaceState(false);
	//std::cout << std::boolalpha << pl.isPlaceState() <<  " ";

	FileConfigurator fc("C:\\Users\\Yapix\\ClionProjects\\cKeyProject\\FileConfigurator\\PlaceState.fc");

	fc.ExtractKeys();

	return 0;
}