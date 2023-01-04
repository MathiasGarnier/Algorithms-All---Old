#include <iostream>

typedef struct LambdaPerson {

    std::string name;
    std:: string surname;
    int age;
};

std::string bar(LambdaPerson *lp);

int main() {

    LambdaPerson lp;
    lp.name = "ola";

    std::operator<<(std::cout, bar(&lp));
    return 0;
}

std::string bar(LambdaPerson *lp) {

    std::string newName(lp->name);
    std::string testName("salutE");

    std::string all;
    all += newName;
    all += testName;

    return all;
}
