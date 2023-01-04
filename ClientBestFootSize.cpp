#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iterator>
#include <algorithm>

#define SUCCESS 0

template<typename T> //Print the content of a std::vector<T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {

    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
    return out;
}

std::vector<std::size_t> fillVector(std::size_t nbValue);
std::size_t choiceBestSize(std::size_t bestSize, std::vector<std::size_t> stock);

int main() {

    //Because I'm lazy, all variables will be initialized using rand()
    //So if you want others values, you must restart the program.

    srand(time(NULL));

    //VAR DECLARATION
    std::size_t skyAsInteger = (rand() % 100) + 1;
    std::size_t clientChoicedSize = (rand() % 100);
    std::vector<std::size_t> stock = fillVector(skyAsInteger);

    //Output log
    std::cout << skyAsInteger << std::endl;    
    std::cout << clientChoicedSize << std::endl;
    std::cout << stock << std::endl;    

    std::cout << choiceBestSize(clientChoicedSize, stock);
    
    return SUCCESS;
}

std::vector<std::size_t> fillVector(std::size_t nbValue) {

    std::size_t value;
    std::size_t counter = 0;

    std::vector<std::size_t> returnedVector;
    
    do {

        value = (rand() % 100) + 1;

        returnedVector.push_back(value);
        
        counter++;
    } while(counter < nbValue);

    std::sort(returnedVector.begin(), returnedVector.end());

    return returnedVector;
}

std::size_t choiceBestSize(std::size_t bestSize, std::vector<std::size_t> stock) {

    for(std::size_t i = 0; i < stock.size(); ++i) {

        if(bestSize == stock.at(i)) return bestSize;
        if(bestSize < stock.at(i) && stock.at(i + 1) != 0) return std::min(bestSize - (stock.at(i - 1)), stock.at(i) - bestSize) == stock.at(i) - bestSize ? stock.at(i) : stock.at(i - 1);
    }
    //[Wreturn-type] 
}
