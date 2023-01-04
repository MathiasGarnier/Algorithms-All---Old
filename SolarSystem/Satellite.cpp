//
// Created by Yapix on 26/02/2017.
//

#include "Satellite.h"

Satellite::Satellite(std::string pIdentifier, long long int pDistanceFromSun, long long int pRadius, long long int nMass) {

	this->setIdentifier(pIdentifier);
	this->setDistanceFromSun(pDistanceFromSun);
	this->setRadius(pRadius);
	this->setMass(nMass);
}
