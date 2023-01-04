/*
 * Shape.h
 *
 *  Created on: 19 mai 2017
 *      Author: Garnier Mathias
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <map>
#include <vector>
#include <utility>
#include <array>
#include "../Cartesian2D.h"

namespace WindGenerator {

	namespace Renderer {

		class Shape : public std::array<char, 930> {

			private:

				/* Warning, the positions is on a grid of 30*30 + 30 (x * x + \n) */
				std::array<char, 930> positions; /* Character */

				bool isShapeDefined;
				bool isShapeLegal;

			public:

				Shape();
				Shape(std::array<char, 930> c);

				void modifyShape(std::array<char, 930>& nS);
		};
	}
}

/* Based on :

#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <iostream>
#include <vector>
#include <string>
#include "../header/location2D.h"

#define _USE_MATH_DEFINES
#include <cmath>

namespace gae {

	class Shape2D {

		 shape => "square", "circle", "triangle",
		 *			 "rectangle", "parallelogram"
		 * start =>  The origine of the shape
		 * percent => Size of the shape, where 100% equals to a volume of 200u, 1% equals to 2u and 200u equals to 1000%
					  A square (c*c) 2u side, has a volume of 3*3 = 9u => 4.5%


		private:

			std::string shapeType;
			gae::Location2D shapeStartPoint;
			double percent;

			bool isShapeTypeDefined;

		public:

			Shape2D();

			std::vector<gae::Location2D> drawSquare(gae::Location2D startPoint, double percentage, bool printableMode);
			std::vector<gae::Location2D> drawCircle(gae::Location2D startPoint, double percentage, bool printableMode);
			std::vector<gae::Location2D> drawTriangle(gae::Location2D startPoint, double percentage, bool printableMode);
			std::vector<gae::Location2D> drawRectangle(gae::Location2D startPoint, double percentage, bool printableMode);
			std::vector<gae::Location2D> drawParallelogram(gae::Location2D startPoint, double percentage, bool printableMode);

			std::vector<gae::Location2D> drawShape(std::string thisShapeType, gae::Location2D startPoint, double percentage, bool printableMode);

			std::vector<gae::Location2D> rotateShape(std::vector<gae::Location2D> shape, double angle, bool printableMode);
			std::vector<gae::Location2D> translateShape(std::vector<gae::Location2D> shape, double distance, bool printableMode);

			std::string getShapeType();
			gae::Location2D getShapeStartPoint();
			double getPercentage();
	};
}

#endif

#include "../header/shape2D.h"

gae::Shape2D::Shape2D() {

	isShapeTypeDefined = false;
}

std::vector<gae::Location2D> gae::Shape2D::drawSquare(gae::Location2D startPoint, double percentage, bool printableMode) {

	isShapeTypeDefined = true;

	shapeType = "square";
	shapeStartPoint = startPoint;
	percent = percentage;

	std::vector<gae::Location2D> finalLocations; Add new value every vertex.
	double unity = 2 * percent;

	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D(), startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() + unity, startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D(), startPoint.getYLocation2D() + unity));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() + unity, startPoint.getYLocation2D() + unity));

	if(printableMode) { for(size_t i = 0; i < finalLocations.size(); ++i) std::cout << finalLocations[i].getXLocation2D() << "\t" <<
																					   finalLocations[i].getYLocation2D() << "\t" << std::endl; }
	else std::cout << "Printable mode is deactived";

	return finalLocations;
}

std::vector<gae::Location2D> gae::Shape2D::drawCircle(gae::Location2D startPoint, double percentage, bool printableMode) {

	isShapeTypeDefined = true;

	shapeType = "circle";
	shapeStartPoint = startPoint;
	percent = percentage;

	std::vector<gae::Location2D> finalLocations;  Add new value every vertex.
	double unity = 2 * percent;

	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D(), startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() + unity, startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() - unity, startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D(), startPoint.getYLocation2D() + unity));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D(), startPoint.getYLocation2D() - unity));

	if(printableMode) { for(size_t i = 0; i < finalLocations.size(); ++i) std::cout << finalLocations[i].getXLocation2D() << "\t" <<
																					   finalLocations[i].getYLocation2D() << "\t" << std::endl; }
	else std::cout << "Printable mode is deactived";

	return finalLocations;

}

std::vector<gae::Location2D> gae::Shape2D::drawTriangle(gae::Location2D startPoint, double percentage, bool printableMode) {

	isShapeTypeDefined = true;

	shapeType = "triangle";
	shapeStartPoint = startPoint;
	percent = percentage;

	std::vector<gae::Location2D> finalLocations;  Add new value every vertex.
	double unity = 2 * percent;

	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D(), startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() + unity, startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() + (unity / 2), startPoint.getYLocation2D() + unity));

	if(printableMode) { for(size_t i = 0; i < finalLocations.size(); ++i) std::cout << finalLocations[i].getXLocation2D() << "\t" <<
																					   finalLocations[i].getYLocation2D() << "\t" << std::endl; }
	else std::cout << "Printable mode is deactived";

	return finalLocations;
}

std::vector<gae::Location2D> gae::Shape2D::drawRectangle(gae::Location2D startPoint, double percentage, bool printableMode) {

	isShapeTypeDefined = true;

	shapeType = "rectangle";
	shapeStartPoint = startPoint;
	percent = percentage;

	std::vector<gae::Location2D> finalLocations;  Add new value every vertex.
	double unity = 2 * percent;

	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D(), startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() + unity, startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D(), startPoint.getYLocation2D() + 2 * unity));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() + unity, startPoint.getYLocation2D() + 2 * unity));

	if(printableMode) { for(size_t i = 0; i < finalLocations.size(); ++i) std::cout << finalLocations[i].getXLocation2D() << "\t" <<
																					   finalLocations[i].getYLocation2D() << "\t" << std::endl; }
	else std::cout << "Printable mode is deactived";

	return finalLocations;
}

std::vector<gae::Location2D> gae::Shape2D::drawParallelogram(gae::Location2D startPoint, double percentage, bool printableMode) {

	isShapeTypeDefined = true;

	shapeType = "parallelogram";
	shapeStartPoint = startPoint;
	percent = percentage;

	std::vector<gae::Location2D> finalLocations;  Add new value every vertex.
	double unity = 2 * percent;

	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D(), startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() + 2 * unity, startPoint.getYLocation2D()));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() + (unity / 3), startPoint.getYLocation2D() + unity));
	finalLocations.push_back(gae::Location2D(startPoint.getXLocation2D() + 2 * unity, startPoint.getYLocation2D() + (unity / 3)));

	if(printableMode) { for(size_t i = 0; i < finalLocations.size(); ++i) std::cout << finalLocations[i].getXLocation2D() << "\t" <<
																					   finalLocations[i].getYLocation2D() << "\t" << std::endl; }
	else std::cout << "Printable mode is deactived";

	return finalLocations;
}

std::vector<gae::Location2D> gae::Shape2D::drawShape(std::string thisShapeType, gae::Location2D startPoint, double percentage, bool printableMode) {

	isShapeTypeDefined = true;

	shapeType = thisShapeType;
	shapeStartPoint = startPoint;
	percent = percentage;

	if(thisShapeType == "square") return drawSquare(startPoint, percentage, printableMode);
	else if(thisShapeType == "circle") return drawCircle(startPoint, percentage, printableMode);
	else if(thisShapeType == "triangle") return drawTriangle(startPoint, percentage, printableMode);
	else if(thisShapeType == "rectangle") return drawRectangle(startPoint, percentage, printableMode);
	else if(thisShapeType == "parallelogram") return drawParallelogram(startPoint, percentage, printableMode);
	else {

		isShapeTypeDefined = false;

		std::cout << "Please specify a valid shapeType (std::string)." << std::endl;

		std::vector<gae::Location2D> locked;
		return locked;
	}
}

std::vector<gae::Location2D> gae::Shape2D::rotateShape(std::vector<gae::Location2D> shape, double angle, bool printableMode) {

	std::vector<gae::Location2D> rotatedShape;

	if(isShapeTypeDefined) {

		double radiansAngle = (M_PI * angle) / 180;

		for(size_t i = 0; i < shape.size(); ++i) {

			double nx = (shape[i].getXLocation2D() * cos(radiansAngle)) - (shape[i].getYLocation2D() * sin(radiansAngle));
			double ny = (shape[i].getXLocation2D() * sin(radiansAngle)) + (shape[i].getYLocation2D() * cos(radiansAngle));

			if(shape[i].getXLocation2D() == 0.0) nx = 0.0;
			if(shape[i].getYLocation2D() == 0.0) ny = 0.0;

			rotatedShape.push_back(gae::Location2D(nx, ny));
		}

		if(printableMode) { for(size_t i = 0; i < rotatedShape.size(); ++i) std::cout << rotatedShape[i].getXLocation2D() << "\t" <<
																							rotatedShape[i].getYLocation2D() << "\t" << std::endl; }
		else std::cout << "Printable mode is deactived";
	} else std::cout << "Please specify a valid shapeType (std::string)." << std::endl;

	return rotatedShape;
}

std::vector<gae::Location2D> gae::Shape2D::translateShape(std::vector<gae::Location2D> shape, double distance, bool printableMode) {

	std::vector<gae::Location2D> translatedShape;

	if(isShapeTypeDefined) {

		for(size_t i = 0; i < shape.size(); ++i) {

			double nx = shape[i].getXLocation2D() + distance;
			double ny = shape[i].getYLocation2D() + distance;

			translatedShape.push_back(gae::Location2D(nx, ny));
		}

		if(printableMode) { for(size_t i = 0; i < translatedShape.size(); ++i) std::cout << translatedShape[i].getXLocation2D() << "\t" <<
																							translatedShape[i].getYLocation2D() << "\t" << std::endl; }
		else std::cout << "Printable mode is deactived";
	} else std::cout << "Please specify a valid shapeType (std::string)." << std::endl;

	return translatedShape;
}


std::string gae::Shape2D::getShapeType() {

	if(isShapeTypeDefined) return shapeType;
	else return "";
}

gae::Location2D gae::Shape2D::getShapeStartPoint() {

	if(isShapeTypeDefined) return shapeStartPoint;
	else return gae::Location2D();
}

double gae::Shape2D::getPercentage() {

	if(isShapeTypeDefined) return percent;
	else return 0.0;
}
*/

#endif /* SHAPE_H_ */
