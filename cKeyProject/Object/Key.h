//
// Created by Yapix on 25/02/2017.
//

#ifndef CKEYPROJECT_KEY_H
#define CKEYPROJECT_KEY_H

#include <string>
#include "Place.h"

class Key {

	private:

		std::string keyOwner;
		int actionRange;
		Place keyFor;

	public:

		/* CONSTRUCTOR */

		Key(std::string nKeyOwner, int nActionRange, Place nKeyFor);

		/* GETTERS AND SETTERS */

		std::string getKeyOwner();
		void setKeyOwner(std::string pOwner);

		int getActionRange();
		void setActionRange(int pActionRange);

		Place getKeyFor();
		void setKeyFor(Place pKeyFor);

		/* UTILITY FUNCTION */

		bool equals(Key other);
};



#endif //CKEYPROJECT_KEY_H
