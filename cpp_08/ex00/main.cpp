#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
	// Vector test
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(20);

	try {
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "Vector found: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Vector: " << e.what() << std::endl;
	}

	// List test
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);

	try {
		std::list<int>::iterator it = easyfind(lst, 25);
		std::cout << "List found: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "List: " << e.what() << std::endl;
	}

	// Deque test
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	try {
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Deque found: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Deque: " << e.what() << std::endl;
	}

	// Value not found
	try {
		std::vector<int>::iterator it = easyfind(vec, 999);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Not found test: " << e.what() << std::endl;
	}

	return 0;
}