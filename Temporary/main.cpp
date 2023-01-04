#include <iostream>

#include "VersionManager.h"
#include "Place.h"
#include "Object.h"

int main() {

    VersionManager::make();

    Place house("HOUSE", true);
    Object<Place> o_house(house);

    std::cout << reinterpret_cast<uintptr_t>(&house);
    std::cout << "o_house ptr : " << o_house.getPtr();

    return 0;
}
