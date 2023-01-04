#include <iostream>
#include <type_traits>
#include <math.h>

template <typename Type1, typename Type2>
	bool comparator(Type1 element1, Type2 element2) {

	if (!(std::is_same<Type1, Type2>::value) ) {

		std::cout << "Les types sont differents, merci de reessayer avec les memes types. Ou alors veuillez changer le type teste.";
		return false;

	} else {

		std::cout << element1 << " et " << element2 << " sont du meme type." << std::endl;

		bool areEquals(element1 == element2);

		std::cout << std::boolalpha << "(" << element1 << " == " << element2 << ") => " << areEquals;
		return areEquals;
	}
}

int main() {

	double x = 5.0, y = log2(32.0);

	comparator<double>(x, y); /* cc @ProfDeMath */
	return 0;
}
