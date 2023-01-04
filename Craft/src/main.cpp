#include <iostream>
#include "Item.h"
#include "CraftEnvironment.h"
#include "Recipe.h"

int main() {
	
	Recipe* recipe = new Recipe(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
								Item::GOLDEN_INGOT, Item::APPLE,     	Item::GOLDEN_INGOT,
								Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT);

	Item diamond_block(45, "diamond_block", recipe);

	std::cout << "5th item in recipe is : " << recipe->getItemName(recipe->getFirstItem()) << std::endl;
	std::cout << *recipe;

	CraftEnvironment::craft(Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT,
							Item::GOLDEN_INGOT, Item::APPLE,        Item::GOLDEN_INGOT,
							Item::GOLDEN_INGOT, Item::GOLDEN_INGOT, Item::GOLDEN_INGOT);
	CraftEnvironment::craft(recipe);

	/* Result : 

			Registering of a new Item.
		        ID = 0
		        name = null_item
		        Have recipe = false
		Registering of a new Item.
		        ID = 1
		        name = wood_stick
		        Have recipe = false
		Registering of a new Item.
		        ID = 2
		        name = iron_ingot
		        Have recipe = false
		Registering of a new Item.
		        ID = 3
		        name = gold_ingot
		        Have recipe = false
		Registering of a new Item.
		        ID = 4
		        name = diamond_ingot
		        Have recipe = false
		Registering of a new Item.
		        ID = 5
		        name = apple
		        Have recipe = false
		Registering of a new Item.
		        ID = 6
		        name = string
		        Have recipe = false
		Registering of a new Item.
		        ID = 45
		        name = diamond_block
		        Have recipe = true
		5th item in recipe is : iron_ingot
		iron_ingot      iron_ingot      iron_ingot
		iron_ingot      apple   iron_ingot
		iron_ingot      iron_ingot      iron_ingot
		YOU CRAFT A GOLDEN APPLE
		YOU CRAFT A GOLDEN APPLE

	*/

	return 0;
}