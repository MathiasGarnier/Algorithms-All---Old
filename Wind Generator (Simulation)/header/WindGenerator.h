/*
 * WindGenerator.h
 *
 *  Created on: 17 mai 2017
 *      Author: Garnier Mathias
 */

#ifndef WINDGENERATOR_H_
#define WINDGENERATOR_H_

#include "Wind.h"
#include "util.h"
#include "Cartesian2D.h"
#include "World.h"
#include "Renderer/Renderer.h"
#include "Renderer/Shape.h"
#include "Physics/Engine.h"
#include "Physics/FunctionWindSpread.h"

namespace WindGenerator {

	void init();
	void draw(); //Using renderer
	void refresh(); //Using renderer
}

#endif /* WINDGENERATOR_H_ */
