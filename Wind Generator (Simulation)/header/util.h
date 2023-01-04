/*
 * util.h
 *
 *  Created on: 17 mai 2017
 *      Author: Garnier Mathias
 */

#ifndef UTIL_H_
#define UTIL_H_

#define _USE_MATH_DEFINES

#include <cmath>
#include <type_traits>
#include <vector>
#include <map>
#include <array>
#include <iterator>
#include <algorithm>
#include "Renderer/Shape.h"

namespace MathsUtil {


	/**
	 * @parameter	x Parameter for do the factorial
	 * @return		The factorial of x
	 */
	std::size_t fact(std::size_t x) {

		if (x <= 1) return 1;

		std::size_t tempbuff = 0;
		tempbuff = x * fact(x - 1);

		return tempbuff;
	}

	/**
	 * @parameter 	v Average speed (in m/s)
	 * @parameter 	A is scale factor (in m/s). A is proportional to average speed
	 * @parameter 	k factor of Weibull shape
	 * @return 		~ wind's speed distribution
	 */
	double distributionOfWeibull(double v, double A, double k) {

		/* 	La vitesse du vent naturel varie en permanence.
		    Pour prévoir la production d'énergie d'une éolienne, il faut connaître la force et la fréquence exactes du vent.
		    On mesure en outre la vitesse moyenne du vent toutes les 10 minutes au moyen d'un anémomètre.
		    Les valeurs obtenues peuvent être réparties en différentes classes variant de 1 m/s.
		    On peut alors exprimer le potentiel énergétique d'un site en fonction de la fréquence des différentes classes de vitesse.

		 	La vitesse du vent naturel varie en permanence.
		    Pour prévoir la production d'énergie d'une éolienne, il faut connaître la force et la fréquence exactes du vent.
		    On mesure en outre la vitesse moyenne du vent toutes les 10 minutes au moyen d'un anémomètre.
		    Les valeurs obtenues peuvent être réparties en différentes classes variant de 1 m/s.
		    On peut alors exprimer le potentiel énergétique d'un site en fonction de la fréquence des différentes classes de vitesse.

			La distribution de Weibull permet souvent une bonne approximation de la distribution de la vitesse du vent:

			A est le facteur d'échelle de Weibull exprimé en m/s; il permet d'exprimer la chronologie d'une vitesse caractéristique.
	 		A est proportionnel à la vitesse moyenne du vent.
			k est le facteur de forme de Weibull. Il donne la forme de la distribution et accepte une valeur de 1 à 3.
			Une valeur plus faible impliquerait un vent très variable alors qu'un vent constant impliquerait une valeur k plus élevée.
		 */

		return k/A * pow(v/A, k - 1) * fact(-pow(v/A, k));
	}

	/**
	 * @parameter	x Number who set the max (ex : Sigma_{0}^{x})
	 * @return		Sigma(0 to x)
	 */
	std::size_t sum(std::size_t x) {

		std::size_t tempbuff = 0;

		for (std::size_t i = 0; i < x + 1; ++i) {

			tempbuff += i;
		}

		return tempbuff;
	}

	/**
	 * @parameter	x Number who set the max (ex : Sigma_{0}^{x})
	 * @return		1 / Sigma(0 to x)
	 */
	std::size_t invertSum(std::size_t x) {

		// 1/(Sigma(0 to x))

		return 1 / sum(x);

	}
}

namespace OperationUtil {

	/**
	 * @parameter	element1 (class template) First argument who compare to element2
	 * @parameter	element2 (class template) Second argument who compare to element1
	 * @return		true if two parameters are of the same type and equals.
	 * @warning		If, we check with two members class, this class must implements operator=
	 */
	template <class Type1, class Type2>
	bool comparator(Type1 element1, Type2 element2) {

		if (!(std::is_same<Type1, Type2>::value) ) {

			return false;

		} else {

			return element1 == element2; //Dependency class must use operator=
		}
	}

	/**
	 * @parameter 	v (const std::vector<template typename T>&) Displayable content.
	 * @return 		Display content of v
	 */
	template<typename T>
	std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {

		std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
		return out;
	}

	/**
	 * @parameter 	v (const std::vector<template typename T, template typename V>&) Displayable content.
	 * @return 		Display content of v
	 */
	template<typename T, typename V>
	std::ostream& operator<<(std::ostream& out, const std::map<T, V>& v) {

	    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
	    return out;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const std::array<T, 24*15>& v) {

		std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ""));
		return out;
	}

	std::array<char, 24*15> rotate(std::array<char, 24*15> array, int factor) {

		std::array<char, 24*15> temp = array;

//		for (std::size_t i = 0; i < 24 * 15; ++i) {
//
//			if (i % 24 == 0) temp[i] = array[i]; //i mod 24 == 0 => mod i, 24
//																	cmp eax, 0
//
//
//		}

		for (std::size_t x = 0; x < 15; ++x) {

			for (std::size_t y = 0; y < 24; ++y) {

				if (y + factor < 24 && y + factor > 0) { //Right shift +

				}
				if (y + factor < 24 && y + factor < 0) { //Left shift -

				}

				if (temp[y] == 24) temp[y] = array[y];
			}
		}
		return temp;
	}

}

namespace Constants {

	//Masse volumique de l'air en fonction de la température

	const double mv_Neg_TEN 		{ 1.341 };
	const double mv_Neg_FIVE 		{ 1.316 };
	const double mv_Nul_ZERO 		{ 1.292 };
	const double mv_Pos_FIVE 		{ 1.269 };
	const double mv_Pos_TEN 		{ 1.247 };
	const double mv_Pos_FIFTEEN 	{ 1.225 };
	const double mv_Pos_TWENTY  	{ 1.204 };
	const double mv_Pos_TWENTYFIVE  { 1.184 };
	const double mv_Pos_THIRTY 		{ 1.164 };
	const double mv_Pos_THIRTYFIVE  { 1.146 };
	const double mv_Pos_FOURTY 		{ 1.127 };

	//Shape

	const std::array<char, 24*15> _NULL 				{};
	const std::array<char, 24*15> START_POSITION 	{ {

/* 1 */	'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '\n',
		' ', '2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '2', ' ', '\n',
		' ', ' ', '3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '3', ' ', ' ', '\n',
		' ', ' ', ' ', '4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '4', ' ', ' ', ' ', '\n',
		' ', ' ', ' ', ' ', '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '5', ' ', ' ', ' ', ' ', '\n',
		' ', ' ', ' ', ' ', ' ', '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '6', ' ', ' ', ' ', ' ', ' ', '\n',
		' ', ' ', ' ', ' ', ' ', ' ', '7', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '7', ' ', ' ', ' ', ' ', ' ', ' ', '\n',
/* 8 */	' ', ' ', ' ', ' ', ' ', ' ', ' ', '8', ' ', ' ', ' ', '*', ' ', ' ', ' ', '8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n',
		' ', ' ', ' ', ' ', ' ', ' ', '7', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '7', ' ', ' ', ' ', ' ', ' ', ' ', '\n',
		' ', ' ', ' ', ' ', ' ', '6', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '6', ' ', ' ', ' ', ' ', ' ', '\n',
		' ', ' ', ' ', ' ', '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '5', ' ', ' ', ' ', ' ', '\n',
		' ', ' ', ' ', '4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '4', ' ', ' ', ' ', '\n',
		' ', ' ', '3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '3', ' ', ' ', '\n',
		' ', '2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '2', ' ', '\n',
/* 15 */'1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '\n',

															} };
}

#endif /* UTIL_H_ */
