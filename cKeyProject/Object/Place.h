//
// Created by Yapix on 25/02/2017.
//

#ifndef CKEYPROJECT_ENUMPLACE_H
#define CKEYPROJECT_ENUMPLACE_H

#include <string>

class Place {

	private:

		std::string name;
		std::string alias;
		bool state = false;

	public:

		static const Place CAR_ENTRY;
		static const Place ENTRY;
		static const Place HOUSE;
		static const Place LIVING_ROOM;
		static const Place BEDROOM;
		static const Place KITCHEN;
		static const Place DINING_ROOM;
		static const Place BATHROOM;
		static const Place ATTIC;
		static const Place GARDEN;

		Place(std::string nName, bool nState);
		Place(std::string pAlias);

		std::string getName();
		void setName(std::string pName);

		bool isPlaceState();
		void setPlaceState(bool pState);

		void lockDoor(Place choose);
		void unlockDoor(Place choose);
};

#endif //CKEYPROJECT_ENUMPLACE_H
