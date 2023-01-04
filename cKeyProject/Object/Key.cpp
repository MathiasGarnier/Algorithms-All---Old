//
// Created by Yapix on 25/02/2017.
//

#include "Key.h"

/* CONSTRUCTOR */

/**
 * @param nKeyOwner The owner of this key
 * @param nActionRange The action range of the key (Well if a door is set to actionRange = 3,
 * 					   a key set to actionRange = 2 can't open the door.
 * @param nKeyFor
 * @usage Construct a new Key in function of his owner and his action range
 * @example Key k("jean louis", 10);
 */
Key::Key(std::string nKeyOwner, int nActionRange, Place nKeyFor) : keyOwner(nKeyOwner), actionRange(nActionRange), keyFor(nKeyFor){}

/* GETTERS AND SETTERS */

/**
 * @usage Get the owner's name
 * @example Key k("jean louis", 10);
 * 			std::cout << k.getKeyOwner(); //Return "jean louis"
 */
std::string Key::getKeyOwner() {

	return keyOwner;
}

/**
 * @param pOwner New value of Owner of the key
 * @usage Set the new value of Owner of the key
 * @example Key k("jean louis", 2);
 * 			k.setKeyOwner("jean");
 * 			k.getKeyOwner(); //Return "jean"
 */
void Key::setKeyOwner(std::string pOwner) {

	this->keyOwner = pOwner;
}

/**
 * @usage Get the action range of the Key
 * @example Key k("jean louis", 3);
 * 			std::cout << k.getActionRange(); //Return 3
 */
int Key::getActionRange() {

	return actionRange;
}

/**
 * @param pActionRange New value of actionRange
 * @usage Set the new value of Key's actionRange
 * @example Key k("jean louis", 2);
 * 			k.setActionRange(k.getActionRange() * 3);
 * 			k.getActionRange(); //Return 6
 */
void Key::setActionRange(int pActionRange) {

	this->actionRange = pActionRange;
}

Place Key::getKeyFor() {

	return keyFor;
}

void Key::setKeyFor(Place pKeyFor) {

	this->keyFor = pKeyFor;
}

/* UTILITY FUNCTION */

/**
 * @param other This is the compared parameter (to this -> this.equals(other))
 * @usage Check if this and other are equals
 * @example Key k("jean louis", 10), k2("jean louis", 10);
 * 			std::cout << std::boolalpha << (std::is_same<decltype(k), decltype(k2)>::value) << std::endl;
 * 			std::cout << std::boolalpha << k.equals(k2); // Return true
 */
bool Key::equals(Key other) {

	return (getKeyOwner() == other.getKeyOwner() && getActionRange() == other.getActionRange());
}
