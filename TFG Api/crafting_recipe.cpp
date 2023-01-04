#include "crafting_recipe.h"

void make_recipe(std::initializer_list<int> line1_, std::initializer_list<int> line2_, std::initializer_list<int> line3_, int result, std::vector<CraftingRecipe>* recipes)
{
    CraftingRecipe recipe;
    std::vector<int> line1 = line1_;
    std::vector<int> line2 = line2_;
    std::vector<int> line3 = line3_;
    recipe.slot1 = line1[0];
    recipe.slot2 = line1[1];
    recipe.slot3 = line1[2];
    recipe.slot4 = line2[0];
    recipe.slot5 = line2[1];
    recipe.slot6 = line2[2];
    recipe.slot7 = line3[0];
    recipe.slot8 = line3[1];
    recipe.slot9 = line3[2];
    recipe.result = result;
    recipes->push_back(recipe);
}
void make_recipe(std::initializer_list<int> line1_, std::initializer_list<int> line2_, int result, std::vector<CraftingRecipe>* recipes)
{
    CraftingRecipe recipe;
    std::vector<int> line1 = line1_;
    std::vector<int> line2 = line2_;
    recipe.slot1 = line1[0];
    recipe.slot2 = line1[1];
    recipe.slot3 = line1[2];
    recipe.slot4 = line2[0];
    recipe.slot5 = line2[1];
    recipe.slot6 = line2[2];
    recipe.slot7 = 0;
    recipe.slot8 = 0;
    recipe.slot9 = 0;
    recipe.result = result;
    recipes->push_back(recipe);
}
void make_recipe(std::initializer_list<int> line1_, int result, std::vector<CraftingRecipe>* recipes)
{
    CraftingRecipe recipe;
    std::vector<int> line1 = line1_;
    recipe.slot1 = line1[0];
    recipe.slot2 = line1[1];
    recipe.slot3 = line1[2];
    recipe.slot4 = 0;
    recipe.slot5 = 0;
    recipe.slot6 = 0;
    recipe.slot7 = 0;
    recipe.slot8 = 0;
    recipe.slot9 = 0;
    recipe.result = result;
    recipes->push_back(recipe);
}
