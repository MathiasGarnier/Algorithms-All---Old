/*
 * Cartesian2D.h
 *
 *  Created on: 17 mai 2017
 *      Author: Garnier Mathias
 */

#ifndef CARTESIAN2D_H_
#define CARTESIAN2D_H_

#include <iostream>

namespace WindGenerator {

	namespace EnvironmentUtil {

		class Cartesian2D {

			private:

				double x;
				double y;

				bool isXYDefined;

			public:

				Cartesian2D();
				Cartesian2D(double _x, double _y);

				void setXY(double nX, double nY);

				double getX() const;
				double getY() const;

				double distanceTo(double dx, double dy);
				double distanceTo(Cartesian2D& d);

				Cartesian2D& translate(double n);
				Cartesian2D& rotate(double theta);

				bool operator==(const Cartesian2D& c);
				Cartesian2D& operator+=(const double& n);
				Cartesian2D& operator+=(const Cartesian2D& c);
				Cartesian2D& operator=(const Cartesian2D& c);
		};
	}
}

#endif /* CARTESIAN2D_H_ */
