#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
	Base* random = generate();
	identify(random);
	identify(*random);
	delete random;
	return 0;
}