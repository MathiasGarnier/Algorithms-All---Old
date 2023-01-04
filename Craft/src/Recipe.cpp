#include "Recipe.h"
#include "Item.h"

Recipe::Recipe(const Item* _one, const Item* _two, const Item* _three, 
			   const Item* _four, const Item* _five, const Item* _six, 
			   const Item* _seven, const Item* _eight, const Item* _nine) : one(_one), two(_two), three(_three),
			   																four(_four), five(_five), six(_six),
			   																seven(_seven), eight(_eight), nine(_nine) {

}

const std::string Recipe::getItemName(const Item* i) const {
	
	return i->itemName;
}

const Item* Recipe::getFirstItem() const {

	return this->one;
}

const Item* Recipe::getSecondItem() const {
	
	return this->two;
}

const Item* Recipe::getThirdItem() const {

	return this->three;
}

const Item* Recipe::getFourthItem() const {

	return this->four;
}

const Item* Recipe::getFifthItem() const {

	return this->five;
}

const Item* Recipe::getSixthItem() const {

	return this->six;
}

const Item* Recipe::getSeventhItem() const {

	return this->seven;
}

const Item* Recipe::getEighthItem() const {

	return this->eight;
}

const Item* Recipe::getNinthItem() const {

	return this->nine;
}

const Recipe* IRON_SHOVEL = new Recipe(Item::NULL_ITEM, Item::IRON_INGOT, Item::NULL_ITEM,
									   Item::NULL_ITEM, Item::WOOD_STICK, Item::NULL_ITEM,
									   Item::NULL_ITEM, Item::WOOD_STICK, Item::NULL_ITEM);
const Recipe* IRON_PICKAXE = new Recipe(Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
										Item::NULL_ITEM,  Item::WOOD_STICK, Item::NULL_ITEM,
										Item::NULL_ITEM,  Item::WOOD_STICK, Item::NULL_ITEM);
const Recipe* IRON_AXE = new Recipe(Item::IRON_INGOT, Item::IRON_INGOT, Item::NULL_ITEM,
									Item::IRON_INGOT, Item::WOOD_STICK, Item::NULL_ITEM,
									Item::NULL_ITEM,  Item::WOOD_STICK, Item::NULL_ITEM);
const Recipe* GOLDEN_SHOVEL = new Recipe(Item::NULL_ITEM, Item::GOLDEN_INGOT, Item::NULL_ITEM,
									     Item::NULL_ITEM, Item::WOOD_STICK,   Item::NULL_ITEM,
									     Item::NULL_ITEM, Item::WOOD_STICK,   Item::NULL_ITEM);
const Recipe* GOLDEN_PICKAXE = new Recipe(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
										  Item::NULL_ITEM,    Item::WOOD_STICK,   Item::NULL_ITEM,
										  Item::NULL_ITEM,    Item::WOOD_STICK,   Item::NULL_ITEM);
const Recipe* GOLDEN_AXE = new Recipe(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::NULL_ITEM,
									  Item::GOLDEN_INGOT, Item::WOOD_STICK,   Item::NULL_ITEM,
								      Item::NULL_ITEM,    Item::WOOD_STICK,   Item::NULL_ITEM);
const Recipe* DIAMOND_SHOVEL = new Recipe(Item::NULL_ITEM, Item::DIAMOND_INGOT, Item::NULL_ITEM,
									      Item::NULL_ITEM, Item::WOOD_STICK,    Item::NULL_ITEM,
									      Item::NULL_ITEM, Item::WOOD_STICK,    Item::NULL_ITEM);
const Recipe* DIAMOND_PICKAXE = new Recipe(Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
										   Item::NULL_ITEM, 	Item::WOOD_STICK, 	 Item::NULL_ITEM,
										   Item::NULL_ITEM,  	Item::WOOD_STICK,    Item::NULL_ITEM);
const Recipe* DIAMOND_AXE = new Recipe(Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::NULL_ITEM,
									   Item::DIAMOND_INGOT, Item::WOOD_STICK,    Item::NULL_ITEM,
									   Item::NULL_ITEM,     Item::WOOD_STICK,    Item::NULL_ITEM);

const Recipe* IRON_SWORD = new Recipe(Item::NULL_ITEM, Item::IRON_INGOT, Item::NULL_ITEM,
									  Item::NULL_ITEM, Item::IRON_INGOT, Item::NULL_ITEM,
									  Item::NULL_ITEM, Item::WOOD_STICK, Item::NULL_ITEM);
const Recipe* GOLDEN_SWORD = new Recipe(Item::NULL_ITEM, Item::GOLDEN_INGOT, Item::NULL_ITEM,
									    Item::NULL_ITEM, Item::GOLDEN_INGOT, Item::NULL_ITEM,
									    Item::NULL_ITEM, Item::WOOD_STICK,   Item::NULL_ITEM);
const Recipe* DIAMOND_SWORD = new Recipe(Item::NULL_ITEM, Item::DIAMOND_INGOT, Item::NULL_ITEM,
									     Item::NULL_ITEM, Item::DIAMOND_INGOT, Item::NULL_ITEM,
									     Item::NULL_ITEM, Item::WOOD_STICK,    Item::NULL_ITEM);

const Recipe* IRON_HELMET = new Recipe(Item::NULL_ITEM,  Item::NULL_ITEM,  Item::NULL_ITEM,
									   Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
									   Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT);
const Recipe* IRON_CHESPLATE = new Recipe(Item::IRON_INGOT, Item::NULL_ITEM, Item::IRON_INGOT,
										  Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
										  Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT);
const Recipe* IRON_LEGGINGS = new Recipe(Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
										 Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT,
										 Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT);
const Recipe* IRON_BOOTS = new Recipe(Item::NULL_ITEM,  Item::NULL_ITEM, Item::NULL_ITEM,
	 								  Item::IRON_INGOT, Item::NULL_ITEM, Item::IRON_INGOT,
	 								  Item::IRON_INGOT, Item::NULL_ITEM, Item::IRON_INGOT);

const Recipe* GOLDEN_HELMET = new Recipe(Item::NULL_ITEM,    Item::NULL_ITEM,    Item::NULL_ITEM,
									     Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
									     Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::GOLDEN_INGOT);
const Recipe* GOLDEN_CHESPLATE = new Recipe(Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::GOLDEN_INGOT,
										    Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
										    Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT);
const Recipe* GOLDEN_LEGGINGS = new Recipe(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
										   Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::GOLDEN_INGOT,
										   Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::GOLDEN_INGOT);
const Recipe* GOLDEN_BOOTS = new Recipe(Item::NULL_ITEM,    Item::NULL_ITEM, Item::NULL_ITEM,
	 								    Item::GOLDEN_INGOT, Item::NULL_ITEM, Item::GOLDEN_INGOT,
	 								    Item::GOLDEN_INGOT, Item::NULL_ITEM, Item::GOLDEN_INGOT);

const Recipe* DIAMOND_HELMET = new Recipe(Item::NULL_ITEM,    Item::NULL_ITEM,    Item::NULL_ITEM,
									     Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
									     Item::DIAMOND_INGOT, Item::NULL_ITEM,    Item::DIAMOND_INGOT);
const Recipe* DIAMOND_CHESPLATE = new Recipe(Item::DIAMOND_INGOT, Item::NULL_ITEM,     Item::DIAMOND_INGOT,
										     Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
										     Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT);
const Recipe* DIAMOND_LEGGINGS = new Recipe(Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
										    Item::DIAMOND_INGOT, Item::NULL_ITEM, 	  Item::DIAMOND_INGOT,
										    Item::DIAMOND_INGOT, Item::NULL_ITEM, 	  Item::DIAMOND_INGOT);
const Recipe* DIAMOND_BOOTS = new Recipe(Item::NULL_ITEM,     Item::NULL_ITEM, Item::NULL_ITEM,
	 								     Item::DIAMOND_INGOT, Item::NULL_ITEM, Item::DIAMOND_INGOT,
	 								     Item::DIAMOND_INGOT, Item::NULL_ITEM, Item::DIAMOND_INGOT);

const Recipe* BUCKET = new Recipe(Item::NULL_ITEM,  Item::NULL_ITEM,  Item::NULL_ITEM,
								  Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT,
								  Item::NULL_ITEM,  Item::IRON_INGOT, Item::NULL_ITEM);
const Recipe* SHEARS = new Recipe(Item::NULL_ITEM,  Item::NULL_ITEM,   Item::NULL_ITEM,
								  Item::NULL_ITEM,  Item::IRON_INGOT,  Item::NULL_ITEM,
								  Item::IRON_INGOT,  Item::NULL_ITEM,  Item::NULL_ITEM);


const Recipe* Recipe::GOLDEN_APPLE = new Recipe(Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
												Item::IRON_INGOT, Item::APPLE,     	Item::IRON_INGOT,
												Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT);
const Recipe* Recipe::BOW = new Recipe(Item::STRING, Item::WOOD_STICK, Item::NULL_ITEM,
									   Item::STRING, Item::NULL_ITEM, Item::WOOD_STICK,
									   Item::STRING, Item::WOOD_STICK, Item::NULL_ITEM);
