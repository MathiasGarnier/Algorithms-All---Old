#include <iostream>
#include "player.h"

using namespace std;

int main(int argc, char* argv[])
{

    std::vector<Player*> Players;
    Players.push_back(new Player("0", "Console", "0"));
    Players.push_back(new Player("1", "Longinus_", "305"));
    Players.push_back(new Player("2", "Playfore38", "306"));

    for (auto const p : Players)
        std::cout << p->username << std::endl;
    std::vector<Player*>::const_iterator iter;
    for(iter = Players.begin(); iter != Players.end(); iter++)
        delete *iter;
    Players.clear();
    return 0;
}