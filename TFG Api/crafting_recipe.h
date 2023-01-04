#ifndef CRAFTING_RECIPE_H
#define CRAFTING_RECIPE_H

#include <initializer_list>
#include <vector>

typedef struct {
    int slot1;
    int slot2;
    int slot3;
    int slot4;
    int slot5;
    int slot6;
    int slot7;
    int slot8;
    int slot9;
    int result;
} CraftingRecipe;

void make_recipe(std::initializer_list<int> line1_, std::initializer_list<int> line2_, std::initializer_list<int> line3_, int result, std::vector<CraftingRecipe>* recipes);
void make_recipe(std::initializer_list<int> line1_, std::initializer_list<int> line2_, int result, std::vector<CraftingRecipe>* recipes);
void make_recipe(std::initializer_list<int> line1_, int result, std::vector<CraftingRecipe>* recipes);

#endif // CRAFTING_RECIPE_H
