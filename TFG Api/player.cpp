#include "player.h"
#define block(x,y,z) World::block(x, y, z)

Player::Player(std::string stream_, std::string username_, std::string uuid_)
{
    stream = stream_;
    username = username_;
    uuid = uuid_;
    x = 0.0;
    y = 0.0;
    z = 60.0;
    health = 20;
    hunger = 60 ;
    is_running = false;
}
Player::~Player()
{
    delete holdItem;
    for(Item* item : inventory)
    {
        delete item;
    }
    inventory.clear();
    effects.clear();
}
std::map<std::string, float> Player::getPos() const
{
    std::map<std::string, float> pos;
    pos["x"] = x;
    pos["y"] = y;
    pos["z"] = z;
    return pos;
}
void Player::updatePos(float x_, float y_, float z_)
{
    x = x_;
    y = y_;
    z = z_;
}
void Player::hurt(Player* attacker)
{
    float damage = 0.0;
    switch(attacker->holdItem->id)
    {
    case Item::I_WOODEN_SWORD:
        damage = 4.0;
        break;
    case Item::I_STONE_SWORD:
        damage = 5.0;
        break;
    case Item::I_GOLDEN_SWORD:
        damage = 4.0;
        break;
    case Item::I_IRON_SWORD:
        damage = 6.0;
        break;
    case Item::I_DIAMOND_SWORD:
        damage = 7.0;
        break;
    }
    if(attacker->holdItem->enchants.find("sharpness") != attacker->holdItem->enchants.end())
    {
        switch(attacker->holdItem->enchants["sharpness"])
        {
        case 1:
            damage *= 1.2;
            break;
        case 2:
            damage *= 1.3;
            break;
        case 3:
            damage *= 1.4;
            break;
        case 4:
            damage *= 1.5;
            break;
        }
    }
    if(block(attacker->x, attacker->y, attacker->z - 1.0) == 0)
        damage *= 1.1;
    if(attacker->is_running)
        damage *= 1.08;
    health -= (int) damage;
}
void Player::send(std::string message)
{
    std::cout << "To " << username << ", " << message << std::endl;
}
bool Player::use(std::string effect)
{
    return holdItem->use(this, effect);
}
bool Player::use()
{
    return holdItem->useAll(this);
}
