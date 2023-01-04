#include <iostream>

void change(int& a, int& b);

int main () {

    int x(NULL);
    int y(NULL);

    std::cin >> x;
    std::cin >> y;

    change(x, y);

    system("pause");
    return 0;
}

void change(int& a, int& b) {

    int t = a;
    a = b;
    b = t;

    std::cout << "First arg : " << a <<std::endl;
    std::cout << "Second arg : " << b <<std::endl;
}
