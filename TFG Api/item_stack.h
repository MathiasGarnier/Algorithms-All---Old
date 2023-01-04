#ifndef ITEM_STACK_H
#define ITEM_STACK_H

#include <iostream>
#include "item.h"

class ItemStack
{
public:
    unsigned int max_item;
    std::vector<Item> item_list;
    ItemStack(int id, int meta_id, int number, int max_item_);
    ItemStack(Item item, int number, int max_item_);
    ~ItemStack();
    ItemStack* divide(int difference);
    bool add(Item* stack_to_add);
    bool add(ItemStack* stack_to_add);
    void update_size(unsigned int new_size);
    unsigned int size() const;
};

#endif // ITEM_STACK_H
