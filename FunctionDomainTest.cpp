#include <iostream>
#include <typeinfo>
#include <cassert>

template<typename T>
class Domain {

	private:

	    T domainValue;

	public:

            Domain(T _domainValue) : domainValue(_domainValue) { std::cout << "Domain ctor" << std::endl; } 
	    T getDomainValue() { return domainValue; }
	    const std::string getDomain() { return typeid(domainValue).name(); }
};	

using Natural = std::size_t;
using Rational = long double;

template<typename Type>
auto MyAlgebraicFunction(Type x) -> Natural {
 
    assert((std::is_same<Type, Natural>::value));

    return x; //Injective, surjective and bijective
}

int main() {

    Natural x = 545;
    Rational nope = 3.1415F;

    Domain<Natural> naturalDomain(x);
    
    std::cout << naturalDomain.getDomainValue() << std::endl;
    std::cout << naturalDomain.getDomain() << std::endl << std::endl;

    MyAlgebraicFunction(x);
    MyAlgebraicFunction(nope); //Program will abort


    return 0;
}
