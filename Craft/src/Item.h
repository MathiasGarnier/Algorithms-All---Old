#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>

class Recipe;

class Item {

	private: //DO GETTER && (maybe) SETTER 

		friend class Recipe;

		std::size_t itemID;
		std::string itemName;
		
		const Recipe* itemRecipe;

		bool haveRecipe;

		std::vector<std::size_t> vectorID; //Do GETTER AND OPERATOR<< OVERLOADING
		std::vector<std::string> vectorName; //DO GETTER

	public:

		Item(const std::size_t _itemID, const std::string _itemName);
		Item(const std::size_t _itemID, const std::string _itemName, const Recipe* _itemRecipe);

	    friend std::ostream& operator<<(std::ostream& out, const Item& i);  
	    Item& operator=(const Item& eq);
	    bool operator==(const Item& eq);

		/* Non-craftable Item : */
		static const Item* NULL_ITEM;

		static const Item* WOOD_STICK; /* Used to craft bow and weapons. */

		static const Item* IRON_INGOT; /* Used to craft weapons and armor. */
		static const Item* GOLDEN_INGOT; /* Used to craft weapons and armor. */
		static const Item* DIAMOND_INGOT; /* Used to craft weapons and armor */

		static const Item* APPLE; /* Used to craft a golden Apple. */
		static const Item* STRING;  /* Used to craft a bow. */

		//const Item SOMETHING(INTEGER, "something", INSERT RECIPE);
};

/* operator<< overloading. */
inline std::ostream& operator<<(std::ostream& out, const Item& i) {

    out << "Registering of a new Item." << std::endl;
	out << "\tID = " << i.itemID << std::endl;
	out << "\tname = " << i.itemName << std::endl;
	out << "\tHave recipe = " << std::boolalpha << i.haveRecipe << std::endl;
	
    return out;  
}  

#endif // ITEM_H