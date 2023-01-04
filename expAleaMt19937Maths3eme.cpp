#include <iostream>
#include <random>
#include <vector>
#include <random>
#include <algorithm>

#define NB_BOULE 100000000 /* Un grand nombre */

struct Boule {

    std::size_t ROUGE = 0; //Id = 1
	std::size_t VERTE = 0; //Id = 2
	std::size_t JAUNE = 0; //Id = 3
    std::size_t BLEU  = 0; //Id = 4

    std::size_t operator[](std::size_t index) {

    	return index;
    }
};

int main() {

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist4(1, 4);

	std::size_t randomNumber;

	std::vector<std::size_t> urne;
	    
    Boule b;

	//On remplit l'urne
	for (int i = 0; i < NB_BOULE; ++i) {

		randomNumber = dist4(rng);

		urne.push_back(b[randomNumber]);
	}    

	//Tirage des boules
	
	b.ROUGE = std::count(urne.begin(), urne.end(), 1);
	b.VERTE = std::count(urne.begin(), urne.end(), 2);
	b.JAUNE = std::count(urne.begin(), urne.end(), 3);
	b.BLEU  = std::count(urne.begin(), urne.end(), 4);

	std::cout << "Pourcentage Rouge : " << (double) b.ROUGE / NB_BOULE << "/1" <<  std::endl;
	std::cout << "Pourcentage verte : " << (double) b.VERTE / NB_BOULE << "/1" << std::endl;	
	std::cout << "Pourcentage jaune : " << (double) b.JAUNE / NB_BOULE << "/1" << std::endl;	
	std::cout << "Pourcentage bleu  : " << (double) b.BLEU  / NB_BOULE << "/1" << std::endl;	

	std::cout << "Total : " << (double) (b.ROUGE + b.VERTE + b.JAUNE + b.BLEU) / NB_BOULE;

	/*
		Pourcentage Rouge : 0.249947/1
		Pourcentage verte : 0.250023/1
		Pourcentage jaune : 0.25002/1
		Pourcentage bleu  : 0.25001/1
		Total : 1	
	*/
}
