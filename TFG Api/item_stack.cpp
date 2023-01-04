#include "item_stack.h"

ItemStack::ItemStack(int id, int meta_id, int number, int max_item_)
{
    if(number > 0)
    {
        for(int i = 0; i < number; ++i)
            item_list.push_back(Item(id, meta_id));
    }
    else
    {
        std::cout << "[ERROR] cannot create a ItemStack of 0 or less items. A stack of 1 item has been created." << std::endl;
        item_list.push_back(Item(id, meta_id));
    }
    max_item = max_item_;
}
ItemStack::ItemStack(Item item, int number, int max_item_)
{
    if(number > 0)
    {
        for(int i = 0; i < number; ++i)
            item_list.push_back(item);
    }
   else
    {
        std::cout << "[ERROR] cannot create a ItemStack of 0 or less items. A stack of 1 item has been created." << std::endl;
        item_list.push_back(item);
    }
    max_item = max_item_;
}
ItemStack::~ItemStack()
{
    item_list.clear();
}
ItemStack* ItemStack::divide(int difference)
{
    int stackNumber;
    Item item = item_list[0];
    stackNumber = item_list.size() - difference;
    item_list.clear();
    for(int i = 0; i < stackNumber; ++i)
        item_list.push_back(item);
    return new ItemStack(item, difference, max_item);
}
bool ItemStack::add(Item* stack_to_add)
{
    if(item_list[0].compare(stack_to_add))
    {
        ItemStack* new_itemStack = new ItemStack(stack_to_add->id, stack_to_add->meta_id, 1, 0);
        if(this->add(new_itemStack))
        {
            delete stack_to_add;
            delete new_itemStack;
            return true;
        }
        else
        {
            delete new_itemStack;
            return false;
        }
    }
    else
        return false;
}
bool ItemStack::add(ItemStack* stack_to_add)
{
    if(item_list[0].compare(&(stack_to_add->item_list[0])))
    {
        if(item_list.size() < max_item)
        {
            unsigned int new_size;
            int id;
            int meta_id;
            new_size = stack_to_add->size();
            id = item_list[0].id;
            meta_id = item_list[0].meta_id;
            while(item_list.size() < max_item && new_size > 0)
            {
                item_list.push_back(Item(id, meta_id));
                new_size--;
            }
            stack_to_add->update_size(new_size);
            if(new_size == 0)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
void ItemStack::update_size(unsigned int new_size)
{
    Item item = item_list[0];
    item_list.clear();
    for(unsigned int i = 0; i < new_size; ++i)
        item_list.push_back(item);
}
unsigned int ItemStack::size() const
{
    return item_list.size();
}
