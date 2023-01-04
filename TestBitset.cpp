#include <iostream>
#include <bitset>
#include <vector>
#include <iterator>
#include <random>

template<typename T> //Print the content of a std::vector<T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {

    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, "\n"));
    return out;
}

int main() {
	
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(0, 65536);

	std::bitset<16> f_line(distribution(rng));
	std::bitset<16> s_line(distribution(rng));
	std::bitset<16> t_line(distribution(rng));

	std::vector< std::bitset<16> > vect_bitset;
	vect_bitset.push_back(f_line);
	vect_bitset.push_back(s_line);
	vect_bitset.push_back(t_line);

	std::cout << vect_bitset;

	std::cout << std::endl << f_line.to_ulong() << std::endl;
	std::cout << s_line.to_ulong() << std::endl << t_line.to_ulong();

	f_line.reset();
	s_line.reset();
	t_line.reset();
	return 0;
}
