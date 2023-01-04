//============================================================================
// Name        : CevelopTest.cpp
// Author      : Mathias Garnier
// Version     : Deprecated
// Copyright   : None
// Description : None
//============================================================================

#include <iostream>
#include <vector>

int main() {

	std::vector<int> vect;

	unsigned int n = 0, size = 0;
	int input = 0;

	std::cin >> size;

	do {

		std::cin >> input;
		vect.push_back(input);

		n++;

	} while (n < size);

	for (int i = 0; i < vect.size(); ++i) {

		std::cout << vect.at(i) << std::endl;
	}
	return 0;
}
