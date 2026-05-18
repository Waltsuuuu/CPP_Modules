#ifndef BASE_HPP
#define BASE_HPP

class Base {
	public:
		virtual ~Base() {};
};

// Randomly creates and allocates A, B or C class (derived from Base)
// and returns it as Base*
Base* generate(void);

// Prints the actal type of the object pointed to by p (A, B or C class)
void identify(Base* p);

// Prints the actual type of of the object referenced by p (A, B or C class)
void identify(Base& p);

#endif