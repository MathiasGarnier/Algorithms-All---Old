#ifndef PLACE_H_INCLUDED
#define PLACE_H_INCLUDED

#include <string>

class Place {

	std::string name;
	bool state;

	public:

        Place() = delete;
		Place(std::string place_name, bool place_state);

		std::string getName();
		void setName(std::string place_name);

		bool isPlaceState();
		void setPlaceState(bool place_state);
};

#endif // PLACE_H_INCLUDED
