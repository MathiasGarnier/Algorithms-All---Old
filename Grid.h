#ifndef GRID_H
#define GRID_H

#include <assert.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>

// #define DEBUG_F

struct Point {

	int x;
	int y;

	bool operator==(Point& value) const {

		return this->x == value.x && this->y == value.y;
	}
};

std::ostream& operator<<(std::ostream& os, const Point& p) {

	os << p.x << "; " << p.y;
	return os;
}

class Grid {

	private:

		int pv_min_x, pv_min_y;
		int pv_max_x, pv_max_y;
		/* Grid : [(min_x, min_y); (max_x, max_y)] */

		double getDistance(Point a, Point b) {

			assert((a.x >= pv_min_x && a.x <= pv_max_x) && (a.y >= pv_min_y && a.y <= pv_max_y));		
			assert((b.x >= pv_min_x && b.x <= pv_max_x) && (b.y >= pv_min_y && b.y <= pv_max_y));

			return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
		}

		double getDistance_wp(Point a, Point b) {

			assert((a.x >= pv_min_x && a.x <= pv_max_x) && (a.y >= pv_min_y && a.y <= pv_max_y));		
			assert((b.x >= pv_min_x && b.x <= pv_max_x) && (b.y >= pv_min_y && b.y <= pv_max_y));

			return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);

		}

	public:

		Grid() = delete;
		Grid(int min_x, int min_y, int max_x, int max_y) : pv_min_x(min_x), pv_min_y(min_y), pv_max_x(max_x), pv_max_y(max_y) {	}

		void haveARightAngle(std::size_t n) {

			srand(time(NULL));
					
			std::size_t counter = 0;
			Point a, b, c;

			do { 
				do {

					a.x = (rand() % ((2 * pv_max_x) + 1)) + (pv_min_x);
					a.y = (rand() % ((2 * pv_max_y) + 1)) + (pv_min_y);
					b.x = (rand() % ((2 * pv_max_x) + 1)) + (pv_min_x);
					b.y = (rand() % ((2 * pv_max_y) + 1)) + (pv_min_y);
					c.x = (rand() % ((2 * pv_max_x) + 1)) + (pv_min_x);
					c.y = (rand() % ((2 * pv_max_y) + 1)) + (pv_min_y);

					#ifdef DEBUG_F
						std::cout << std::endl << "1 " << a << b << c;
					#endif
				} while(a == b || a == c || b == c ||
						getDistance(a, b) == (getDistance(b, c) + getDistance(a, c)) ||
						getDistance(b, c) == (getDistance(a, b) + getDistance(a, c)) || 
						getDistance(a, c) == (getDistance(a, b) + getDistance(b, c))); // Pour ne pas avoir des points confondus et donc un triangle non utilisable.
				
				double tmp_length[] = { getDistance_wp(a, b), getDistance_wp(b, c), getDistance_wp(c, a) };	
				std::vector<double> tmp_vect(tmp_length, tmp_length + 3);
				std::sort(tmp_vect.begin(), tmp_vect.begin() + 3);

				double hypo_length = *std::max_element(tmp_length, tmp_length + 3);
				double f_length = tmp_vect.at(0);
				double s_length = tmp_vect.at(1);

				if(hypo_length == f_length + s_length) std::cout << "Fond one ! Where \n\ta = (" << a << ")\n\tb = (" << b << ")\n\tc = (" << c << ")" << std::endl; 

				counter++;
			} while(counter < n);
		}
};

#endif // GRID_H
