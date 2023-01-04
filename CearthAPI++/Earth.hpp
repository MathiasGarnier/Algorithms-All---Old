#ifndef EARTH_HPP_INCLUDED
#define EARTH_HPP_INCLUDED

#include <iostream>
#include <string>

/*
        This class discribe the Eartj !
        Author Yapix
*/

class Earth
{
    public:
    Earth();
    Earth(std::string e_Name);
    ~Earth();
    void rarity_In_Galaxy(long rarity, long percent_Of_Chance);


    private:
    int people_capacity;
    long people_Alive_On_Earth;

};

#endif // EARTH_HPP_INCLUDED
