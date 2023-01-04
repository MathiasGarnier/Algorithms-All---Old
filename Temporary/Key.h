#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED

#include <string>

#include "Place.h"

class Key {

		std::string keyOwner;
		int actionRange;
		Place keyFor;

	public:

        Key() = delete;
		Key(std::string nKeyOwner, int nActionRange, Place nKeyFor);

		std::string getKeyOwner();
		void setKeyOwner(std::string pOwner);

		int getActionRange();
		void setActionRange(int pActionRange);

		Place getKeyFor();
		void setKeyFor(Place pKeyFor);

		bool equals(Key other);
};

#endif // KEY_H_INCLUDED
