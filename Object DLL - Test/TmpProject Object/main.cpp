#include <iostream>
#include "../Object/Object.h"
#include "../Object/main.h"

int main() {

    Object<int> instance(15);
    int substitution(instance.getContent() << 2);

    instance.cast<int>(substitution);
    std::cout << instance.getContent();

    return 0;
}
