#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"

#include <string>
#include <map>
#include <iostream>
#include "world.h"

class Player
{
public:
    std::vector<Item*> inventory;
    std::map<int, int> effects;
    Item* holdItem;
    std::string stream;
    std::string username;
    std::string uuid;
    std::string ip;

    float x;
    float y;
    float z;
    int health;
    int hunger;
    int laggometer;
    bool is_running;

    Player(std::string stream_, std::string username_, std::string uuid_);
    ~Player();
    std::map<std::string, float> getPos() const;
    void updatePos(float x_, float y_, float z_);
    void hurt(Player* attacker);
    void send(std::string message);
    bool use(std::string effect);
    bool use();
};

#endif // PLAYER_H
