#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
	Base* random = generate();
	(void)random;
	return 0;
}