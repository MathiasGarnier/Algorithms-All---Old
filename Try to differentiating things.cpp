#include <iostream>
#include <functional>
#include <cassert>
#include <cmath>

//Approximation, fuck. Hate.
//Dans les startings blocks.

typedef std::function<double(double)> fun;

//f'(x) = lim t -> 0 (f(x+t)-f(x))/t
//Let f is at least a C^1 function and fuck everything else
//Rigour ? ahah
double differentiate(fun function, double x) {

	auto dx = 10e-7;
	return (function(x + dx) - function(x)) / dx;
}

//C^2
double second_derivative(fun function, double x) {

	auto dx = 10e-7;
	return (differentiate(function, x + dx) - differentiate(function, x)) / dx;
}

//C^n
double nth_derivative(std::size_t nth, fun function, double x) {

	assert(nth > 1);

	auto dx = 10e-7;
	auto r = 0;

	for (std::size_t i = 1; i < nth; ++i) {

		r = (differentiate(function, x + dx) - differentiate(function, x)) / dx;
	}

	return r;
}

double f(double x) {

	return x * x * exp(x);
}

int main() {

	std::cout << differentiate(f, 15) << std::endl; // print << df/dx
	std::cout << second_derivative(f, 15) << std::endl; // print << d^2f/dx^2
	std::cout << nth_derivative(4, f, 15) << std::endl;

	return 0;
}
