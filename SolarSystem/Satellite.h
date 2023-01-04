//
// Created by Yapix on 26/02/2017.
//

#ifndef SOLARSYSTEM_API_SATELLITE_H
#define SOLARSYSTEM_API_SATELLITE_H

#include "Planet.h"

class Satellite : public Planet {

	private:

		std::string identifier;
		long long int distanceFromSun;
		long long int radius;
		long long int mass; /* mass*10^21 */

	public:

		Satellite(std::string pIdentifier, long long int pDistanceFromSun, long long int pRadius, long long int nMass);
};

#endif //SOLARSYSTEM_API_SATELLITE_H
