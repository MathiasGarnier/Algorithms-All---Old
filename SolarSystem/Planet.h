//
// Created by Yapix on 26/02/2017.
//

#ifndef SOLARSYSTEM_API_PLANET_H
#define SOLARSYSTEM_API_PLANET_H

#include <string>
#include <iostream>

class Planet {

	private:

		std::string identifier;
		long long int distanceFromSun;
		long long int radius;
		long long int mass; /* mass*10^21 */

	public:

		Planet();
		Planet(std::string pIdentifier, long long int pDistanceFromSun, long long int pRadius, long long int mass);

		const std::string &getIdentifier() const;
		void setIdentifier(const std::string &nIdentifier);

		long long int getDistanceFromSun() const;
		void setDistanceFromSun(long long int nDistanceFromSun);

		long long int getRadius() const;
		void setRadius(long long int nRadius);

		long long int getMass();
		void setMass(long long int nMass);

		/* Comparator Planet and Satellite */

		template<typename Type>
		bool compare(Type element1);
};


template<typename Type>
bool Planet::compare(Type element1) {

	return (element1.getIdentifier() == getIdentifier() && element1.getDistanceFromSun() == getDistanceFromSun()
		        && element1.getRadius() == getRadius() && element1.getMass() == getMass());
}

#endif //SOLARSYSTEM_API_PLANET_H
