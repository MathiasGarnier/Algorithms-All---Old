//
// Created by Yapix on 25/02/2017.
//

#include <iostream>
#include "Place.h"

/* Define as Place("alias", doorState) */
/* This is the start configuration (change by a file) */
const Place Place::CAR_ENTRY = Place("car_entry", false);
const Place Place::ENTRY = Place("entry", false);
const Place Place::HOUSE = Place("house", false);
const Place Place::LIVING_ROOM = Place("living_room", false);
const Place Place::BEDROOM = Place("bedroom", false);
const Place Place::KITCHEN = Place("kitchen", false);
const Place Place::DINING_ROOM = Place("dining_room", false);
const Place Place::BATHROOM = Place("bathroom", false);
const Place Place::ATTIC = Place("attic", false);
const Place Place::GARDEN = Place("garden", false);

Place::Place(std::string nName, bool nState) {

	this->setName(nName);
	this->setPlaceState(nState);
}

Place::Place(std::string pAlias) {

	this->setName(pAlias);
	this->setPlaceState(this->isPlaceState());
}

std::string Place::getName() {

	return name;
}

void Place::setName(std::string pName) {

	this->name = pName;
}

bool Place::isPlaceState() {

	return state;
}

void Place::setPlaceState(bool pState) {

	this->state = pState;
}
