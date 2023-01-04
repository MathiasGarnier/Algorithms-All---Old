#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <map>

#ifndef PLAYER_H
struct Player
{
    std::string getUuid() const;
};
#endif

class World
{
private:
    int         player_count;
    int         max_build_height;
    long        worldAge;
    std::string level_name;
    std::map<std::string, Player*> handled_players;
public:
    int     autosave_interval;
    int     sea_level;
    long    day_length;
    long    time;
    bool    pvp;
    bool    spawn_animals;
    bool    spawn_mobs;

    World(std::string path, int save_interval, int dayLength = 24000, int seaLevel = 64);
    void create_entity(int type, Player* player);
    std::string getWorldName() const;
    int playersCount() const;
    int block(float, float, float);
};

#endif // WORLD_H
