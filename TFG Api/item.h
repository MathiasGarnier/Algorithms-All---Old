#ifndef ITEM_H
#define ITEM_H

class Player;

#include <vector>
#include <string>
#include <map>
#include <functional>

class Item
{
public:
    int id;
    int meta_id;
    int durablity;
    std::string name;
    std::map<std::string, int> enchants;
    std::map<std::string, std::function<void(Player*)>> effects;

    Item(int id_, int meta_id_);
    Item();
    ~Item();
    void add_enchant(std::string enchant, int level);
    void add_effect(std::string name, std::function<void(Player*)> effect);
    bool use(Player* user, std::string effect);
    bool useAll(Player* user);
    bool compare(Item* item);
    static bool static_compare(Item* item1, Item* item2);



    //Enchant List:
    static const int E_PROTECTION = 0;
    static const int E_FIRE_PROCTECTION = 1;
    static const int E_FEATHER_FALLING = 2;
    static const int E_BLAST_PROTECTION = 3;
    static const int E_PROJECTILE_PROTECTION = 4;
    static const int E_RESPIRATION = 5;
    static const int E_AQUA_AFFINITY = 6;
    static const int E_THORNS = 7;
    static const int E_DEPTH_STRIDER = 8;
    static const int E_FROST_WALKER = 9;
    static const int E_SHARPNESS = 16;
    static const int E_SMITE = 17;
    static const int E_BANE_OF_ARTHROPODS = 18;
    static const int E_KNOCKBACK = 19;
    static const int E_FIRE_ASPECT = 20;
    static const int E_LOOTING = 21;
    static const int E_EFFICIENCY = 32;
    static const int E_SILK_TOUCH = 33;
    static const int E_UNBREAKING = 34;
    static const int E_FORTUNE = 35;
    static const int E_POWER = 48;
    static const int E_PUNCH = 49;
    static const int E_FLAME = 50;
    static const int E_INFINITY = 51;
    static const int E_LUCK_OF_THE_SEA = 61;
    static const int E_LURE = 62;
    static const int E_MENDING = 70;


    //Item List:
	static const int I_AIR = 0;
	static const int I_STONE = 1;
	static const int I_GRANITE = 1;
	static const int I_POLISHED_GRANITE = 1;
	static const int I_DIORITE = 1;
	static const int I_POLISH_DIORITE = 1;
	static const int I_ANDESITE = 1;
	static const int I_POLISHED_ANDESITE = 1;
	static const int I_GRASS = 2;
	static const int I_DIRT = 3;
	static const int I_COARSE_DIRT = 3;
	static const int I_PODZOL = 3;
	static const int I_COBBLESTONE = 4;
	static const int I_COBBLE = 4;
	static const int I_WOODEN_PLANK = 5;
	static const int I_WOODEN_PLANK_OAK = 5;
	static const int I_WOODEN_PLANK_SPRUCE = 5;
	static const int I_WOODEN_PLANK_BIRCH = 5;
	static const int I_WOODEN_PLANK_JUNGLE = 5;
	static const int I_WOODEN_PLANK_ACACIA = 5;
	static const int I_WOODEN_PLANK_DARK_OAK = 5;
	static const int I_WOODEN_PLANKS = 5;
	static const int I_WOODEN_PLANKS_OAK = 5;
	static const int I_WOODEN_PLANKS_SPRUCE = 5;
	static const int I_WOODEN_PLANKS_BIRCH = 5;
	static const int I_WOODEN_PLANKS_JUNGLE = 5;
	static const int I_WOODEN_PLANKS_ACACIA = 5;
	static const int I_WOODEN_PLANKS_DARK_OAK = 5;
	static const int I_SAPPLING = 6;
	static const int I_SAPPLING_OAK = 6;
	static const int I_SAPPLING_SPRUCE = 6;
	static const int I_SAPPLING_BIRCH = 6;
	static const int I_SAPPLING_JUNGLE = 6;
	static const int I_SAPPLING_ACACIA = 6;
	static const int I_SAPPLING_DARK_OAK = 6;
	static const int I_BEDROCK = 7;
	static const int I_WATER = 8;
	static const int I_FLOWING_WATER = 9;
	static const int I_LAVA = 10;
	static const int I_FLOWING_LAVA = 11;
	static const int I_SAND = 12;
	static const int I_RED_SAND = 12;
	static const int I_GRAVEL = 13;
	static const int I_GOLD_ORE = 14;
	static const int I_IRON_ORE = 15;
	static const int I_COAL_ORE = 16;
	static const int I_WOOD = 17;
	static const int I_WOOD_OAK = 17;
	static const int I_WOOD_SPRUCE = 17;
	static const int I_WOOD_BIRCH = 17;
	static const int I_WOOD_JUNGLE = 17;
	static const int I_WOOD_ACACIA = 17;
	static const int I_WOOD_DARK_OAK = 17;
	static const int I_LEAVES = 18;
	static const int I_LEAVES_OAK = 18;
	static const int I_LEAVES_SPRUCE = 18;
	static const int I_LEAVES_BIRCH = 18;
	static const int I_LEAVES_JUNGLE = 18;
	static const int I_LEAVES_ACACIA = 18;
	static const int I_LEAVES_DARK_OAK = 18;
	static const int I_SPONGE = 19;
	static const int I_WET_SPONGE = 19;
	static const int I_GLASS = 20;
	static const int I_LAPIS_ORE = 21;
	static const int I_LAPIS_LAZULI_ORE = 21;
	static const int I_LAPIS_BLOCK = 22;
	static const int I_LAPIS_LAZULI_BLOCK = 22;
	static const int I_DISPENSER = 23;
	static const int I_SANDSTONE = 24;
	static const int I_SANDSTONE_CHISELED = 24;
	static const int I_SANDSTONE_SMOOTH = 24;
	static const int I_NOTE_BLOCK = 25;
	static const int I_NOTEBLOCK = 25;
	static const int I_BED_BLOCK = 26;
	static const int I_RAIL_POWERED = 27;
	static const int I_POWERED_RAIL = 27;
	static const int I_GOLDEN_RAIL = 27;
	static const int I_RAIL_DETECTOR = 28;
	static const int I_DETECTOR_RAIL = 28;
	static const int I_STICKY_PISTON = 29;
	static const int I_COBWEB = 30;
	static const int I_WEB = 30;
	static const int I_TALLGRASS_DEAD_SHRUB = 31;
	static const int I_TALLGRASS_DEADSHRUB = 31;
	static const int I_TALLGRASS = 31;
	static const int I_TALLGRASS_FERN = 31;
	static const int I_DEAD_SHRUB = 32;
	static const int I_DEADSHRUB = 32;
	static const int I_PISTON = 33;
	static const int I_PISTON_HEAD = 34;
	static const int I_WOOL = 35;
	static const int I_WOOL_WHITE = 35;
	static const int I_WOOL_ORANGE = 35;
	static const int I_WOOL_MAGENTA = 35;
	static const int I_WOOL_LIGHT_BLUE = 35;
	static const int I_WOOL_LIGHTBLUE = 35;
	static const int I_WOOL_YELLOW = 35;
	static const int I_WOOL_LIME = 35;
	static const int I_WOOL_PINK = 35;
	static const int I_WOOL_GRAY = 35;
	static const int I_WOOL_LIGHTGRAY = 35;
	static const int I_WOOL_LIGHT_GRAY = 35;
	static const int I_WOOL_GREY = 35;
	static const int I_WOOL_LIGHTGREY = 35;
	static const int I_WOOL_LIGHT_GREY = 35;
	static const int I_WOOL_CYAN = 35;
	static const int I_WOOL_PURPLE = 35;
	static const int I_WOOL_BLUE = 35;
	static const int I_WOOL_BROWN = 35;
	static const int I_WOOL_GREEN = 35;
	static const int I_WOOL_RED = 35;
	static const int I_WOOL_BLACK = 35;
	static const int I_PISTON_EXTENSION = 36;
	static const int I_DANDELION = 37;
	static const int I_YELLOW_FLOWER = 37;
	static const int I_ROSE = 38;
	static const int I_POPPY = 38;
	static const int I_ORCHID = 38;
	static const int I_BLUE_ORCHID = 38;
	static const int I_ALIUM = 38;
	static const int I_BLUET = 38;
	static const int I_AZURE_BLUET = 38;
	static const int I_TULIP = 38;
	static const int I_RED_TULIP = 38;
	static const int I_ORANGE_TULIP = 38;
	static const int I_WHITE_TULIP = 38;
	static const int I_PINK_TULIP = 38;


	static const int I_WOODEN_SWORD = 268;
	static const int I_STONE_SWORD = 272;
	static const int I_GOLDEN_SWORD = 283;
	static const int I_IRON_SWORD = 267;
	static const int I_DIAMOND_SWORD = 276;
};

#endif // ITEM_H
