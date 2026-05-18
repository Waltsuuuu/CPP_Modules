#include "Base.hpp"
#include "Aclass.hpp"
#include "Bclass.hpp"
#include "Cclass.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void) {
	int random = rand() % 3;

	if (random == 0) {
		std::cout << "Generated A class" << std::endl;
		return new Aclass;
	}
	if (random == 1) {
		std::cout << "Generated B class" << std::endl;
		return new Bclass;
	}
	std::cout << "Generated C class" << std::endl; 
	return new Cclass;
}

// Identify the real derived type using dynamic_cast on pointers.
// Failed pointer casts return NULL.
void identify(Base* p) {
	if (!p) {
		std::cout << "Pointer is null" << std::endl;
		return;
	}
	if (dynamic_cast<Aclass*>(p)) {
		std::cout << "Pointer is class A" << std::endl;
	}
	else if (dynamic_cast<Bclass*>(p)) {
		std::cout << "Pointer is class B" << std::endl;
	}
	else if (dynamic_cast<Cclass*>(p)) {
		std::cout << "Pointer is class C" << std::endl;
	}
	else {
		std::cout << "Unknown pointer" << std::endl;
	}
}

// Identify the real derived type using dynamic_cast on references.
// Failed reference casts throw an exception.
void identify(Base& p) {
	try {
		Aclass& a = dynamic_cast<Aclass&>(p);
		(void)a;
		std::cout << "Reference is class A" << std::endl;
		return;
	} catch (...) {
	}

	try {
		Bclass& b = dynamic_cast<Bclass&>(p);
		(void)b;
		std::cout << "Reference is class B" << std::endl;
		return;
	} catch (...) {
	}

	try {
		Cclass& c = dynamic_cast<Cclass&>(p);
		(void)c;
		std::cout << "Reference is class C" << std::endl;
		return;
	} catch (...) {
	}
}