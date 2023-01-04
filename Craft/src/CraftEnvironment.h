#ifndef CRAFTENVIRONMENT_H
#define CRAFTENVIRONMENT_H

#include <iostream>
#include "Recipe.h"
#include "Item.h"

#define craft_if_it(on, tw, th, fo, fi, si, se, ei, ni) if(one == on && two == tw && three == th && four == fo && five == fi && six == si && seven == se && eight == ei && nine == ni)
#define craft_if_re(on, tw, th, fo, fi, si, se, ei, ni) if(r->getFirstItem() == on && r->getSecondItem() == tw && r->getThirdItem() == th && r->getFourthItem() == fo && r->getFifthItem() == fi && r->getSixthItem() == si && r->getSeventhItem() == se && r->getEighthItem() == ei && r->getNinthItem() == ni)
#define youcraft(thing) std::cout << "YOU CRAFT : " << thing << std::endl;

namespace CraftEnvironment {

	void craft(const Item* one, const Item* two, const Item* three, 
	           const Item* four, const Item* five, const Item* six, 
	           const Item* seven, const Item* eight, const Item* nine) { 

		craft_if_it(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
					Item::GOLDEN_INGOT, Item::APPLE,        Item::GOLDEN_INGOT,
				 	Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT)
			youcraft("GOLDEN APPLE")
		craft_if_it(Item::STRING, Item::WOOD_STICK, Item::NULL_ITEM,
					Item::STRING, Item::NULL_ITEM,  Item::WOOD_STICK,
					Item::STRING, Item::WOOD_STICK, Item::NULL_ITEM)
			youcraft("BOW")
		craft_if_it(Item::NULL_ITEM, Item::IRON_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK, Item::NULL_ITEM)
			youcraft("IRON SHOVEL")
		craft_if_it(Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
					Item::NULL_ITEM,  Item::WOOD_STICK, Item::NULL_ITEM,
					Item::NULL_ITEM,  Item::WOOD_STICK, Item::NULL_ITEM)
			youcraft("IRON PICKAXE")
		craft_if_it(Item::IRON_INGOT, Item::IRON_INGOT, Item::NULL_ITEM,
					Item::IRON_INGOT, Item::WOOD_STICK, Item::NULL_ITEM,
					Item::NULL_ITEM,  Item::WOOD_STICK, Item::NULL_ITEM)
			youcraft("IRON AXE")
		craft_if_it(Item::NULL_ITEM, Item::GOLDEN_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK,   Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK,   Item::NULL_ITEM)
			youcraft("GOLDEN SHOVEL")
		craft_if_it(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
					Item::NULL_ITEM,    Item::WOOD_STICK,   Item::NULL_ITEM,
					Item::NULL_ITEM,    Item::WOOD_STICK,   Item::NULL_ITEM)
			youcraft("GOLDEN PICKAXE")
		craft_if_it(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::NULL_ITEM,
					Item::GOLDEN_INGOT, Item::WOOD_STICK,   Item::NULL_ITEM,
					Item::NULL_ITEM,    Item::WOOD_STICK,   Item::NULL_ITEM)
			youcraft("GOLDEN AXE")
		craft_if_it(Item::NULL_ITEM, Item::DIAMOND_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK,    Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK,    Item::NULL_ITEM)
			youcraft("DIAMOND SHOVEL")
		craft_if_it(Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
					Item::NULL_ITEM, 	 Item::WOOD_STICK, 	  Item::NULL_ITEM,
					Item::NULL_ITEM,  	 Item::WOOD_STICK,    Item::NULL_ITEM)
			youcraft("DIAMOND PICKAXE")
		craft_if_it(Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::NULL_ITEM,
					Item::DIAMOND_INGOT, Item::WOOD_STICK,    Item::NULL_ITEM,
					Item::NULL_ITEM,     Item::WOOD_STICK,    Item::NULL_ITEM)
			youcraft("DIAMOND AXE")
		craft_if_it(Item::NULL_ITEM, Item::IRON_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::IRON_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK, Item::NULL_ITEM)
			youcraft("DIAMOND SWORD")
		craft_if_it(Item::NULL_ITEM, Item::GOLDEN_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::GOLDEN_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK,   Item::NULL_ITEM)
			youcraft("GOLDEN SWORD")
		craft_if_it(Item::NULL_ITEM,  Item::DIAMOND_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM,  Item::DIAMOND_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM,  Item::WOOD_STICK,    Item::NULL_ITEM)
			youcraft("DIAMOND SWORD")
		craft_if_it(Item::NULL_ITEM,  Item::NULL_ITEM,  Item::NULL_ITEM,
					Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
					Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT)
			youcraft("IRON HELMET")
		craft_if_it(Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT,
					Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
					Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT)
			youcraft("IRON CHESPLATE")
		craft_if_it(Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
					Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT,
					Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT)
			youcraft("IRON LEGGINGS")
		craft_if_it(Item::NULL_ITEM,  Item::NULL_ITEM, Item::NULL_ITEM,
	 				Item::IRON_INGOT, Item::NULL_ITEM, Item::IRON_INGOT,
	 				Item::IRON_INGOT, Item::NULL_ITEM, Item::IRON_INGOT)
			youcraft("IRON BOOTS")
		craft_if_it(Item::NULL_ITEM,    Item::NULL_ITEM,    Item::NULL_ITEM,
					Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
					Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::GOLDEN_INGOT)
			youcraft("GOLDEN HELMET")
		craft_if_it(Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::IRON_INGOT,
					Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
					Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT)
			youcraft("GOLDEN CHESPLATE")
		craft_if_it(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
					Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::GOLDEN_INGOT,
					Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::GOLDEN_INGOT)
			youcraft("GOLDEN LEGGINGS")
		craft_if_it(Item::NULL_ITEM,    Item::NULL_ITEM, Item::NULL_ITEM,
	 				Item::GOLDEN_INGOT, Item::NULL_ITEM, Item::GOLDEN_INGOT,
	 				Item::GOLDEN_INGOT, Item::NULL_ITEM, Item::GOLDEN_INGOT)
			youcraft("GOLDEN BOOTS")		
		craft_if_it(Item::NULL_ITEM,     Item::NULL_ITEM,  	  Item::NULL_ITEM,
					Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
					Item::DIAMOND_INGOT, Item::NULL_ITEM,     Item::DIAMOND_INGOT)
			youcraft("DIAMOND HELMET")
		craft_if_it(Item::DIAMOND_INGOT, Item::NULL_ITEM,     Item::DIAMOND_INGOT,
					Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
					Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT)
			youcraft("DIAMOND CHESPLATE")
		craft_if_it(Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
					Item::DIAMOND_INGOT, Item::NULL_ITEM,     Item::DIAMOND_INGOT,
					Item::DIAMOND_INGOT, Item::NULL_ITEM,     Item::DIAMOND_INGOT)
			youcraft("DIAMOND LEGGINGS")
		craft_if_it(Item::NULL_ITEM,     Item::NULL_ITEM, Item::NULL_ITEM,
	 				Item::DIAMOND_INGOT, Item::NULL_ITEM, Item::DIAMOND_INGOT,
	 				Item::DIAMOND_INGOT, Item::NULL_ITEM, Item::DIAMOND_INGOT)
			youcraft("DIAMOND BOOTS")
		craft_if_it(Item::NULL_ITEM,  Item::NULL_ITEM,  Item::NULL_ITEM,
					Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT,
					Item::NULL_ITEM,  Item::IRON_INGOT, Item::NULL_ITEM)
			youcraft("BUCKET")
		craft_if_it(Item::NULL_ITEM,   Item::NULL_ITEM,   Item::NULL_ITEM,
					Item::NULL_ITEM,   Item::IRON_INGOT,  Item::NULL_ITEM,
					Item::IRON_INGOT,  Item::NULL_ITEM,   Item::NULL_ITEM)
			youcraft("SHEARS")
	}

	void craft(const Recipe* r) {

		craft_if_re(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
					Item::GOLDEN_INGOT, Item::APPLE,        Item::GOLDEN_INGOT,
				 	Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT)
			youcraft("GOLDEN APPLE")
		craft_if_re(Item::STRING, Item::WOOD_STICK, Item::NULL_ITEM,
					Item::STRING, Item::NULL_ITEM,  Item::WOOD_STICK,
					Item::STRING, Item::WOOD_STICK, Item::NULL_ITEM)
			youcraft("BOW")
		craft_if_re(Item::NULL_ITEM, Item::IRON_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK, Item::NULL_ITEM)
			youcraft("IRON SHOVEL")
		craft_if_re(Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
					Item::NULL_ITEM,  Item::WOOD_STICK, Item::NULL_ITEM,
					Item::NULL_ITEM,  Item::WOOD_STICK, Item::NULL_ITEM)
			youcraft("IRON PICKAXE")
		craft_if_re(Item::IRON_INGOT, Item::IRON_INGOT, Item::NULL_ITEM,
					Item::IRON_INGOT, Item::WOOD_STICK, Item::NULL_ITEM,
					Item::NULL_ITEM,  Item::WOOD_STICK, Item::NULL_ITEM)
			youcraft("IRON AXE")
		craft_if_re(Item::NULL_ITEM, Item::GOLDEN_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK,   Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK,   Item::NULL_ITEM)
			youcraft("GOLDEN SHOVEL")
		craft_if_re(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
					Item::NULL_ITEM,    Item::WOOD_STICK,   Item::NULL_ITEM,
					Item::NULL_ITEM,    Item::WOOD_STICK,   Item::NULL_ITEM)
			youcraft("GOLDEN PICKAXE")
		craft_if_re(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::NULL_ITEM,
					Item::GOLDEN_INGOT, Item::WOOD_STICK,   Item::NULL_ITEM,
					Item::NULL_ITEM,    Item::WOOD_STICK,   Item::NULL_ITEM)
			youcraft("GOLDEN AXE")
		craft_if_re(Item::NULL_ITEM, Item::DIAMOND_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK,    Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK,    Item::NULL_ITEM)
			youcraft("DIAMOND SHOVEL")
		craft_if_re(Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
					Item::NULL_ITEM, 	 Item::WOOD_STICK, 	  Item::NULL_ITEM,
					Item::NULL_ITEM,  	 Item::WOOD_STICK,    Item::NULL_ITEM)
			youcraft("DIAMOND PICKAXE")
		craft_if_re(Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::NULL_ITEM,
					Item::DIAMOND_INGOT, Item::WOOD_STICK,    Item::NULL_ITEM,
					Item::NULL_ITEM,     Item::WOOD_STICK,    Item::NULL_ITEM)
			youcraft("DIAMOND AXE")
		craft_if_re(Item::NULL_ITEM, Item::IRON_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::IRON_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK, Item::NULL_ITEM)
			youcraft("DIAMOND SWORD")
		craft_if_re(Item::NULL_ITEM, Item::GOLDEN_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::GOLDEN_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM, Item::WOOD_STICK,   Item::NULL_ITEM)
			youcraft("GOLDEN SWORD")
		craft_if_re(Item::NULL_ITEM,  Item::DIAMOND_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM,  Item::DIAMOND_INGOT, Item::NULL_ITEM,
					Item::NULL_ITEM,  Item::WOOD_STICK,    Item::NULL_ITEM)
			youcraft("DIAMOND SWORD")
		craft_if_re(Item::NULL_ITEM,  Item::NULL_ITEM,  Item::NULL_ITEM,
					Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
					Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT)
			youcraft("IRON HELMET")
		craft_if_re(Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT,
					Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
					Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT)
			youcraft("IRON CHESPLATE")
		craft_if_re(Item::IRON_INGOT, Item::IRON_INGOT, Item::IRON_INGOT,
					Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT,
					Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT)
			youcraft("IRON LEGGINGS")
		craft_if_re(Item::NULL_ITEM,  Item::NULL_ITEM, Item::NULL_ITEM,
	 				Item::IRON_INGOT, Item::NULL_ITEM, Item::IRON_INGOT,
	 				Item::IRON_INGOT, Item::NULL_ITEM, Item::IRON_INGOT)
			youcraft("IRON BOOTS")
		craft_if_re(Item::NULL_ITEM,    Item::NULL_ITEM,    Item::NULL_ITEM,
					Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
					Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::GOLDEN_INGOT)
			youcraft("GOLDEN HELMET")
		craft_if_re(Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::IRON_INGOT,
					Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
					Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT)
			youcraft("GOLDEN CHESPLATE")
		craft_if_re(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
					Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::GOLDEN_INGOT,
					Item::GOLDEN_INGOT, Item::NULL_ITEM,    Item::GOLDEN_INGOT)
			youcraft("GOLDEN LEGGINGS")
		craft_if_re(Item::NULL_ITEM,    Item::NULL_ITEM, Item::NULL_ITEM,
	 				Item::GOLDEN_INGOT, Item::NULL_ITEM, Item::GOLDEN_INGOT,
	 				Item::GOLDEN_INGOT, Item::NULL_ITEM, Item::GOLDEN_INGOT)
			youcraft("GOLDEN BOOTS")		
		craft_if_re(Item::NULL_ITEM,     Item::NULL_ITEM,  	  Item::NULL_ITEM,
					Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
					Item::DIAMOND_INGOT, Item::NULL_ITEM,     Item::DIAMOND_INGOT)
			youcraft("DIAMOND HELMET")
		craft_if_re(Item::DIAMOND_INGOT, Item::NULL_ITEM,     Item::DIAMOND_INGOT,
					Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
					Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT)
			youcraft("DIAMOND CHESPLATE")
		craft_if_re(Item::DIAMOND_INGOT, Item::DIAMOND_INGOT, Item::DIAMOND_INGOT,
					Item::DIAMOND_INGOT, Item::NULL_ITEM,     Item::DIAMOND_INGOT,
					Item::DIAMOND_INGOT, Item::NULL_ITEM,     Item::DIAMOND_INGOT)
			youcraft("DIAMOND LEGGINGS")
		craft_if_re(Item::NULL_ITEM,     Item::NULL_ITEM, Item::NULL_ITEM,
	 				Item::DIAMOND_INGOT, Item::NULL_ITEM, Item::DIAMOND_INGOT,
	 				Item::DIAMOND_INGOT, Item::NULL_ITEM, Item::DIAMOND_INGOT)
			youcraft("DIAMOND BOOTS")
		craft_if_re(Item::NULL_ITEM,  Item::NULL_ITEM,  Item::NULL_ITEM,
					Item::IRON_INGOT, Item::NULL_ITEM,  Item::IRON_INGOT,
					Item::NULL_ITEM,  Item::IRON_INGOT, Item::NULL_ITEM)
			youcraft("BUCKET")
		craft_if_re(Item::NULL_ITEM,   Item::NULL_ITEM,   Item::NULL_ITEM,
					Item::NULL_ITEM,   Item::IRON_INGOT,  Item::NULL_ITEM,
					Item::IRON_INGOT,  Item::NULL_ITEM,   Item::NULL_ITEM)
			youcraft("SHEARS")
	}
}

#endif // CRAFTENVIRONMENT_H