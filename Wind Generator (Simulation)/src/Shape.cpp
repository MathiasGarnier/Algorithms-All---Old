/*
 * Shape.cpp
 *
 *  Created on: 20 mai 2017
 *      Author: Garnier Mathias
 */

#include "../header/Renderer/Shape.h"

WindGenerator::Renderer::Shape::Shape() {

	isShapeDefined = false;
	isShapeLegal = false;
}

WindGenerator::Renderer::Shape::Shape(std::array<char, 930> c) {

	isShapeDefined = true;
	if (c.size() == 30 * 30 + 30) {

		isShapeLegal = true;
		positions = c;
	}
}

void WindGenerator::Renderer::Shape::modifyShape(std::array<char, 930>& nS) {

	if (isShapeLegal || nS.size() == 30 * 30 + 30) positions = nS;
}
