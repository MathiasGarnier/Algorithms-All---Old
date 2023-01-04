#ifndef RECIPE_H
#define RECIPE_H

#include <array>
#include <iostream>

class Item;

class Recipe {

	private:

		const Item* one; //DO GETTERS
		const Item* two;
		const Item* three;
		const Item* four;
		const Item* five;
		const Item* six;
		const Item* seven;
		const Item* eight;
		const Item* nine;

		//std::array<Item*, 9> vectorRecipe;

	public:

		Recipe(const Item* _one, const Item* _two, const Item* _three, 
			   const Item* _four, const Item* _five, const Item* _six, 
			   const Item* _seven, const Item* _eight, const Item* _nine);
		//Recipe(std::array<Item*, 9> _vectorRecipe); 

		static void addNewRecipe(Item* _one, Item* _two, Item* _three, Item* _four, Item* _five, Item* _six, Item* _seven, Item* _eight, Item* _nine);
		//static void addNewRecipe(std::array<Item*, 9> _vectorRecipe);
   		const std::string getItemName(const Item* i) const;

	    friend std::ostream& operator<<(std::ostream& out, const Recipe& i);  

		const Item* getFirstItem() const;
		const Item* getSecondItem() const;
		const Item* getThirdItem() const;
		const Item* getFourthItem() const;
		const Item* getFifthItem() const;
		const Item* getSixthItem() const;
		const Item* getSeventhItem() const;
		const Item* getEighthItem() const;
		const Item* getNinthItem() const;

		static const Recipe* IRON_SHOVEL;
		static const Recipe* IRON_PICKAXE;
		static const Recipe* IRON_AXE;
		static const Recipe* GOLDEN_SHOVEL;
		static const Recipe* GOLDEN_PICKAXE;
		static const Recipe* GOLDEN_AXE;
		static const Recipe* DIAMOND_SHOVEL;
		static const Recipe* DIAMOND_PICKAXE;
		static const Recipe* DIAMOND_AXE;

		static const Recipe* IRON_SWORD;
		static const Recipe* GOLDEN_SWORD;
		static const Recipe* DIAMOND_SWORD;

		static const Recipe* IRON_HELMET;
		static const Recipe* IRON_CHESPLATE;
		static const Recipe* IRON_LEGGINGS;
		static const Recipe* IRON_BOOTS;

		static const Recipe* GOLDEN_HELMET;
		static const Recipe* GOLDEN_CHESPLATE;
		static const Recipe* GOLDEN_LEGGINGS;
		static const Recipe* GOLDEN_BOOTS;

		static const Recipe* DIAMOND_HELMET;
		static const Recipe* DIAMOND_CHESPLATE;
		static const Recipe* DIAMOND_LEGGINGS;
		static const Recipe* DIAMOND_BOOTS;

		static const Recipe* BUCKET;
		static const Recipe* SHEARS;

		static const Recipe* GOLDEN_APPLE;
		static const Recipe* BOW;
};

/* operator<< overloading. */
inline std::ostream& operator<<(std::ostream& out, const Recipe& r) {

    out << r.getItemName(r.getFirstItem()) << "\t" << r.getItemName(r.getSecondItem()) << "\t" << r.getItemName(r.getThirdItem()) << std::endl;
    out << r.getItemName(r.getFourthItem()) << "\t" << r.getItemName(r.getFifthItem()) << "\t" << r.getItemName(r.getSixthItem()) << std::endl;
    out << r.getItemName(r.getSeventhItem()) << "\t" << r.getItemName(r.getEighthItem()) << "\t" << r.getItemName(r.getNinthItem()) << std::endl;

    return out;  
}  

#endif // RECIPE_H_