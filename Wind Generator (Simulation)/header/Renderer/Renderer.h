/*
 * Renderer.h
 *
 *  Created on: 19 mai 2017
 *      Author: Garnier Mathias
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include "Shape.h"

namespace WindGenerator {

	namespace Renderer {

		class Renderer : public Shape {

			private:
			public:

				void render(Shape s);
				void refresh(Shape s);
		};
	}
}


/* Faire des rotation(EACH POINT) sur ça de theta = x degrees /!\ trouver x plus tard
 * Et du coup faire une actualisation frame par frame de Sleep(~70) pour avoir un rendu graphique
 * Vitesse des pales dépendra de la vitesse du vent !


 	 	 	 		  *
 	 	 	 	  	 *
 	 	 	 	   *
 	 	 	 	 *
 	 	 	 	*
 */

#endif /* RENDERER_H_ */
