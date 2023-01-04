/*
 * Cartesian2D.cpp
 *
 *  Created on: 17 mai 2017
 *      Author: Garnier Mathias
 */

#include "../header/Cartesian2D.h"
#include <cmath>

WindGenerator::EnvironmentUtil::Cartesian2D::Cartesian2D() {

	this->x = 0;
	this->y = 0;
	isXYDefined = false;
}

WindGenerator::EnvironmentUtil::Cartesian2D::Cartesian2D(double _x, double _y) {

	this->x = _x;
	this->y = _y;

	isXYDefined = true;
}

void WindGenerator::EnvironmentUtil::Cartesian2D::setXY(double nX, double nY) {

	this->x = nX;
	this->y = nY;

	isXYDefined = true;
}

double WindGenerator::EnvironmentUtil::Cartesian2D::getX() const {

	if(isXYDefined) return x;
	else return 0;
}
double WindGenerator::EnvironmentUtil::Cartesian2D::getY() const {

	if(isXYDefined) return y;
	else return 0;
}

double WindGenerator::EnvironmentUtil::Cartesian2D::distanceTo(double dx, double dy) {

	if(isXYDefined) return sqrt(pow(dx - this->getX(), 2) + pow(dy - this->getY(), 2));
	else return 0;
}

double WindGenerator::EnvironmentUtil::Cartesian2D::distanceTo(WindGenerator::EnvironmentUtil::Cartesian2D& d) {

	if(isXYDefined) return sqrt(pow(d.getX() - this->getX(), 2) + pow(d.getY() - this->getY(), 2));
	else return 0;
}

WindGenerator::EnvironmentUtil::Cartesian2D& WindGenerator::EnvironmentUtil::Cartesian2D::translate(double n) {

	if(isXYDefined) *this += n;

	return *this;
}

WindGenerator::EnvironmentUtil::Cartesian2D& WindGenerator::EnvironmentUtil::Cartesian2D::rotate(double theta) {

	if(isXYDefined) {

		this->x += this->getX() * cos(theta) - this->getY() * sin(theta);
		this->y += this->getX() * sin(theta) + this->getY() * cos(theta);
	}

	return *this;
}

bool WindGenerator::EnvironmentUtil::Cartesian2D::operator==(const WindGenerator::EnvironmentUtil::Cartesian2D& c) {

	if(isXYDefined) return this->getX() == c.getX() && this->getY() == c.getY();
	else return false;

}

WindGenerator::EnvironmentUtil::Cartesian2D& WindGenerator::EnvironmentUtil::Cartesian2D::operator+=(const double& n) {

	this->x += n;
	this->y += n;

	return *this;
}

WindGenerator::EnvironmentUtil::Cartesian2D& WindGenerator::EnvironmentUtil::Cartesian2D::operator+=(const WindGenerator::EnvironmentUtil::Cartesian2D& c) {

	this->x += c.x;
	this->y += c.y;

	return *this;
}

WindGenerator::EnvironmentUtil::Cartesian2D& WindGenerator::EnvironmentUtil::Cartesian2D::operator=(const WindGenerator::EnvironmentUtil::Cartesian2D& c) {

	this->x = c.x;
	this->y = c.y;

	return *this;
}
