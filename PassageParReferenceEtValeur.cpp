#include <iostream>

void val(int x);
void ref(int &x);

int main() {

    int a(3);

    val(a);
    std::cout << a;

    ref(a);
    std::cout << a;

    //5355
    
    return 0;
}

void val(int x) {

    x += 2;
    std::cout << x;
}

void ref(int &x) {

    x += 2;
    std::cout << x;
}
