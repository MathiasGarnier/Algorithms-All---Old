#include <iostream>
#include <fstream>

int main() {

    char url[100] = "https://youtube.com/watch?v=ageGa5w2qPc"; //Joke.

    std::fstream fs;

    unsigned int instance = 0;
    while (true) { //Attention faut pas rester trop longtemps par ce que l'ordinateur va pas trop aimer huhu x) ^^'.

        fs.open(url);
        fs.close();

        instance++;
        std::cout << instance << std::endl;
    }

    return 0;
}
