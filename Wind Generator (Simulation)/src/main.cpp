/*
 * main.cpp
 *
 *  Created on: 17 mai 2017
 *      Author: Garnier Mathias
 */

#include <iostream>
#include "../header/WindGenerator.h" // Import unique (pas besoin de plus)

using namespace OperationUtil;
using namespace Constants;
using namespace WindGenerator::Renderer;

class Shape;

int main() {

//	WindGenerator::EnvironmentUtil::Cartesian2D c(10, 12);
//	WindGenerator::EnvironmentUtil::Cartesian2D c1(10, 12);

//	bool equals = OperationUtil::comparator(c, c1);
//
//	std::cout << std::boolalpha << equals << std::endl;

//	std::cout << c.getX();
//	std::cout << " " << c.getY() << " ";
//
//	std::cout << "" << std::endl;
//	c.rotate(MathsUtil::invertSum(2));
//	std::cout << c.getX();
//	std::cout << " " << c.getY() << " ";

	std::cout << START_POSITION;

	std::array<char, 24*15> rotated = rotate(START_POSITION, 2);

	std::cout << rotated;
	return 0;
}
