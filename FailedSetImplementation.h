#ifndef SET_H
#define SET_H

//FAILED, I will remake it later.

#include <iostream>
#include <complex>

namespace bm {

	namespace fundamental {

		/**
		 *  Set<T> class
		 */
		template<typename T> //example :  (PUSH_BACK INTO DOXYGEN DOCUMENTATION) Set<Natural> x, y; auto n = x + y;
		class Set {

			protected:

				/*mutable*/ T value; 

			public: 

				Set() { std::cout << "IN BASIC SET CTOR" << std::endl; }
				Set(T _value) : value(_value) { std::cout << "IN SET CTOR" << std::endl; }
				~Set() {std::cout << "set dtor"; }

				T& operator+(const T& st);
				T& operator-(const T& st);
				T& operator*(const T& st);
				T& operator/(const T& st);
				T& operator%(const T& st);

				T& operator+=(const T& st);
				T& operator-=(const T& st);
				T& operator*=(const T& st);
				T& operator/=(const T& st);
				T& operator%=(const T& st);

				T& operator++(); //prefix
				T& operator++(int unused); //postfix
				T& operator--(); //prefix
				T& operator--(int unused); //postfix

				T& operator=(T const &st);

				bool operator==(const T& st) const;
				bool operator!=(const T& st) const;
				bool operator>(const T& st) const;
				bool operator>=(const T& st) const;
				bool operator<(const T& st) const;
				bool operator<=(const T& st) const;
				
				//do ! && || & | ^ &= |= ^= <<= >>= 
				// conversion operator ?

				//std::ostream& operator<<(std::ostream& out, const T& st);
		};

		using Natural =  Set<std::size_t>;
		using Integer = Set<long long int>;
		using Real = Set<long double>;
		template<typename T> 
		using Complex = Set<std::complex<T>>; //Check if template T is numeric : is_fundamental<T>::value
	}
}

#endif
