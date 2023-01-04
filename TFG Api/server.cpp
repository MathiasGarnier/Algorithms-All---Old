#include "server.h"

Server::Server()
{
    is_running = false;
}
void Server::start(int port_, std::string ip_, int max_player_)
{
    port = port_;
    ip = ip_;
    max_player = max_player_;
    is_running = true;
}
void Server::stop()
{
    is_running = false;
}
bool Server::run()
{
    return is_running;
}
void Server::broadcast(std::string message, std::vector<Player*>* playerlist)
{
    std::vector<Player*>::const_iterator iter;
    for(iter = playerlist->begin(); iter != playerlist->end(); iter++)
        (*iter)->send(message);
}
