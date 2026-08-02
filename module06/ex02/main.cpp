#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
	int r = std::rand() % 3;
	if (r == 0) return new A();
	else if (r == 1) return new B();
	else return new C();
}

// not an X = nullptr
void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

// not an X = exception
void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (...) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (...) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (...) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

int main() {
	std::srand(std::time(NULL));
	for (size_t i = 0; i < 10; i++) {
		Base* ptr = generate();

		std::cout << "Pointer id:	";
		identify(ptr);
		std::cout << "Reference id:	";
		identify(ptr);
		delete ptr;
		std::cout << "------------------" << std::endl;
	}
	return 0;
}