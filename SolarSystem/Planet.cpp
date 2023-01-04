//
// Created by Yapix on 26/02/2017.
//

#include "Planet.h"

Planet::Planet() {}

Planet::Planet(std::string pIdentifier, long long int pDistanceFromSun, long long int pRadius, long long int nMass) {

	this->setIdentifier(pIdentifier);
	this->setDistanceFromSun(pDistanceFromSun);
	this->setRadius(pRadius);
	this->setMass(nMass);
}

const std::string &Planet::getIdentifier() const {

	return identifier;
}

void Planet::setIdentifier(const std::string &nIdentifier) {

	this->identifier = nIdentifier;
}

long long int Planet::getDistanceFromSun() const {

	return distanceFromSun;
}

void Planet::setDistanceFromSun(long long int nDistanceFromSun) {

	this->distanceFromSun = nDistanceFromSun;
}

long long int Planet::getRadius() const {

	return radius;
}

void Planet::setRadius(long long int nRadius) {

	this->radius = nRadius;
}


long long int Planet::getMass() {

	return mass;
}

void Planet::setMass(long long int nMass) {

	this->mass = nMass;
}