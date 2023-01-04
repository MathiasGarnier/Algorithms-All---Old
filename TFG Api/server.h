#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include "player.h"
//headers to do...

class Server
{
public:
    Server();
    void start(int port_, std::string ip_, int max_player_);
    void stop();
    bool run();
    void setMax(int max_player_);
    void send_packet(std::string stream, std::string value);
    void send_packet(std::string stream, int value);
    void send_packet(std::string stream, float value);
    void send_packet(std::string stream, double value);
    void broadcast(std::string message, std::vector<Player*>* playerlist);
    std::string chat(Player* sender, std::string message);

private:
    int port;
    int max_player;
    bool is_running;
    std::string ip;
    std::vector<std::string> playerList;
};



#endif // SERVER_H
