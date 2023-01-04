#include <iostream>

class Player {

    public:

        Player() {}

        std::string setName(std::string _name)   { _name.append("\'s ");  return _name; }
        std::string _setName(std::string &_name) { _name.append("\'s "); return _name; }
};

int main() {

    Player p0;
    Player p1;

    std::string name("User");

    std::cout << p0.setName(name);
    std::cout << name << " ";

    std::cout << p1._setName(name);
    std::cout << name;

    return 0;
}
