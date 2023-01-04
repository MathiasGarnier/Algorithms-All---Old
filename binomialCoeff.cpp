#include <iostream>

//Compile it as > g++ filename.cpp -option1 -option2 -std=c++11 -o main.exe
//By exemple > g++ binomialCoeff.cpp -Wall -std=c++11 -o main.exe

std::size_t binomialCoeff(std::size_t n, std::size_t k);
std::size_t fact(std::size_t x);

int main() {

	std::size_t n, k;


	std::cout << "n >> ";
	std::cin >> n;

	std::cout << std::endl << "k >> ";
	std::cin >> k;
	
	std::cout << std::endl << "(n k) = " << binomialCoeff(n, k);
	
	return 0;
}

std::size_t binomialCoeff(std::size_t n, std::size_t k) {

	
	// Because I use 'std::size_t' type, max = 0xFFFFFFFFUL
	 
	if (k > n) return 0;
	else return fact(n) / (fact(k) * fact(n - k));
}

std::size_t fact(std::size_t x) {

	std::size_t tempbuff;
	
	if (x <= 1) return 1;
	
	tempbuff = x * fact(x - 1);

	return tempbuff;
}
