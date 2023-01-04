#include <iostream>

class Player {

    public:

        Player() {}

        std::string setName(std::string _name)   { _name.append("\'s ");  return _name; }
        std::string _setName(std::string &_name) { _name.append("\'s "); return _name; }

        void swapName(Player &a, std::string _aName, Player& b, std::string _bName) {

            std::string _a(a._setName(_aName));
            std::string _b(b._setName(_bName));
            std::string tmp(_a);
            _a = _b;
            _b = tmp;

            std::cout << _a << ", " << _b;
        }
};

int main() {

    Player p0;
    Player p1;

    std::string name("User");
    std::string nameF("Orange");
    std::string nameS("Blue");

    std::cout << p0.setName(name);
    std::cout << name << " ";

    std::cout << p1._setName(name);
    std::cout << name;

    std::cout << "\n*************************\n";
    std::cout << "p0 : " << p0._setName(nameF);
    std::cout << "p1 : " << p1._setName(nameS);
    std::cout << "\n*************************\n";

    Player c;
    c.swapName(p0, "Orange", p1, "Blue");
    return 0;
}
