#include <iostream>

namespace Lambda {

    struct Person {

        std::string name;
        std::string surname;
    };
}
std::string getName(Lambda::Person *lp);
std::string setName(Lambda::Person *lp, std::string nName, std::string nSurname);

int main() {

    Lambda::Person lp;

    lp.name = "Jean";
    lp.surname = "Marc";

    std::operator<<(std::cout, getName(&lp)) << std::endl;
    std::operator<<(std::cout, setName(&lp, "Richard", "Gasquet")) << std::endl;
    std::operator<<(std::cout, getName(&lp)) << std::endl;

    return 0;
}

std::string getName(Lambda::Person *lp) {

    std::string globalName;

    std::string nName(lp->name);
    std::string nSurname(lp->surname);

    globalName += nName + " " + nSurname;


    return globalName;
}

std::string setName(Lambda::Person *lp, std::string nName, std::string nSurname) {

    std::string nGlobalName(nName + " " + nSurname);

    lp->name = nName, lp->surname = nSurname;

    return nGlobalName;
}
