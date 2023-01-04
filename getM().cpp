#include <iostream>
#include <vector>
#include <algorithm>

int getM(std::vector<int> t);

int main() {
    
    std::vector<int> t;
    t.push_back(5);
    t.push_back(29);
    t.push_back(3);
    t.push_back(15);
    t.push_back(1);
    t.push_back(1);
    t.push_back(45);
    t.push_back(1);

    std::cout << getM(t);

    return 0;
}

int getM(std::vector<int> t) {

    std::sort(t.begin(), t.end());

    for (auto a : t)
        std::cout << a << " ";

    if (t.size() % 2 == 0)
        return (t.size() / 2) + ((t.size() / 2) + 1) / 2;
    else
        return t.size() / 2;
}
