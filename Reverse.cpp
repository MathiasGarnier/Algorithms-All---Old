#include <iostream>

std::string reverse(std::string str) {

    std::string newStr;

    for (int i = str.size(); i >= 0; --i) {

        newStr += str[i];
    }

    return newStr;
}

int main() {

    std::cout << reverse("Hello it's me Mario !");

    return 0;
}
