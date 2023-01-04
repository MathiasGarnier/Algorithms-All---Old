#include "Item.h"
#include "Recipe.h"

Item::Item(const std::size_t _itemID, const std::string _itemName) {

	itemID = _itemID;
	itemName = _itemName;
	haveRecipe = false;

/*
	std::cout << "Registering of a new Item." << std::endl;
	std::cout << "\tID = " << itemID << std::endl;
	std::cout << "\tname = " << itemName << std::endl;
	std::cout << "\tHave recipe = " << std::boolalpha << haveRecipe << std::endl;
*/

	std::cout << *this;

	vectorID.push_back(itemID);
	vectorName.push_back(itemName);
}

Item::Item(const std::size_t _itemID, const std::string _itemName, const Recipe* _itemRecipe) {

	itemID = _itemID;
	itemName = _itemName;
	haveRecipe = true;

/*
	std::cout << "Registering of a new Item." << std::endl;
	std::cout << "\tID = " << itemID << std::endl;
	std::cout << "\tname = " << itemName << std::endl;
	std::cout << "\tHave recipe = " << std::boolalpha << haveRecipe << std::noboolalpha << std::endl;
	std::cout << "\tRecipe = " << std::endl<< *_itemRecipe;
*/

	std::cout << *this;

	vectorID.push_back(itemID);
	vectorName.push_back(itemName);

	// @todo GERER RECIPE
	//itemRecipe = _itemRecipe;
}

Item& Item::operator=(const Item& eq) {

	if(!(this->haveRecipe) && !(eq.haveRecipe)) {

		/* Don't need to update haveRecipe value. */
		this->itemID = eq.itemID;
		this->itemName = eq.itemName;

		//DELETE in vectorID && vectorName instance ? NOPE
	} else {

		this->itemID = eq.itemID;
		this->itemName = eq.itemName;
		this->itemRecipe = eq.itemRecipe; //make Recipe::operator= i guess
	}

	return *this;
}

bool Item::operator==(const Item& eq) {

	if(!(this->haveRecipe) && !(eq.haveRecipe)) {

		if((this->itemID == eq.itemID) && (this->itemName == eq.itemName)) return true;
		else return false;
	} else {

		if((this->itemID == eq.itemID) && (this->itemName == eq.itemName) && (this->itemRecipe == eq.itemRecipe)) return true; //Do Recipe::operator== i guess
		else return false;
	}
}

const Item* Item::NULL_ITEM = new Item(0, "null_item");
const Item* Item::WOOD_STICK = new Item(1, "wood_stick");
const Item* Item::IRON_INGOT = new Item(2, "iron_ingot");
const Item* Item::GOLDEN_INGOT = new Item(3, "gold_ingot");
const Item* Item::DIAMOND_INGOT = new Item(4, "diamond_ingot");
const Item* Item::APPLE = new Item(5, "apple");
const Item* Item::STRING = new Item(6, "string");

