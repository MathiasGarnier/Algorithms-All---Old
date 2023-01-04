#include "Place.h"

Place::Place(std::string place_name, bool place_state) : name(place_name), state(place_state) { }

std::string Place::getName() {

    return name;
}

void Place::setName(std::string place_name) {

    name = place_name;
}

bool Place::isPlaceState() {

    return state;
}

void Place::setPlaceState(bool place_state) {

    state = place_state;
}
