#include "item.h"

Item::Item(int id_, int meta_id_)
{
    id = id_;
    meta_id = meta_id_;
}
Item::Item()
{
    id = 0;
    meta_id = 0;
}
Item::~Item()
{
    enchants.clear();
    effects.clear();
}
void Item::add_enchant(std::string enchant, int level)
{
    enchants[enchant] = level;
}
void Item::add_effect(std::string name, std::function<void(Player*)> effect)
{
    effects[name] = effect;
}
bool Item::use(Player* user, std::string effect)
{
    if(effects.find(effect) != effects.end())
    {
        effects[effect](user);
        return true;
    }
    else
        return false;
}
bool Item::useAll(Player* user)
{
    bool test = false;
    std::map<std::string, std::function<void(Player*)>>::const_iterator iter;
    for(iter = effects.begin(); iter != effects.end(); iter++)
    {
        iter->second(user);
        test = true;
    }
    return test;
}
bool Item::compare(Item* item)
{
    return Item::static_compare(this, item);
}
bool Item::static_compare(Item* item1, Item* item2)
{
    return (item1->id == item2->id && item1->meta_id == item2->meta_id && item1->name == item2->name);
}
