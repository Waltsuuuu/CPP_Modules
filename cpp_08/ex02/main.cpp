#include "MutantStack.hpp"
#include <iostream>
#include <list>

static void printHeader(const std::string& title)
{
	std::cout << "\n========================================\n";
	std::cout << title << std::endl;
	std::cout << "========================================\n";
}

int main()
{
	printHeader("TEST 1: Normal stack functionality");

	MutantStack<int> mstack;

	std::cout << "Pushing: 5, 17" << std::endl;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;

	std::cout << "\nPopping top element..." << std::endl;
	mstack.pop();

	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;


	printHeader("TEST 2: Add more elements");

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Current stack size: "
			  << mstack.size() << std::endl;


	printHeader("TEST 3: Forward iteration");

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Elements:" << std::endl;

	while (it != ite)
	{
		std::cout << "  " << *it << std::endl;
		++it;
	}


	printHeader("TEST 4: Reverse iteration");

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << "Elements in reverse:" << std::endl;

	while (rit != rite)
	{
		std::cout << "  " << *rit << std::endl;
		++rit;
	}


	printHeader("TEST 5: Copy constructor");

	MutantStack<int> copy(mstack);

	std::cout << "Copied stack contents:" << std::endl;

	for (MutantStack<int>::iterator it = copy.begin();
		 it != copy.end();
		 ++it)
	{
		std::cout << "  " << *it << std::endl;
	}


	printHeader("TEST 6: Assignment operator");

	MutantStack<int> assigned;

	assigned = mstack;

	std::cout << "Assigned stack contents:" << std::endl;

	for (MutantStack<int>::iterator it = assigned.begin();
		 it != assigned.end();
		 ++it)
	{
		std::cout << "  " << *it << std::endl;
	}


	printHeader("TEST 7: Subject comparison");

	std::cout << "MutantStack behaves like a normal stack:"
			  << std::endl;

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Top after pop: "
			  << mstack.top() << std::endl;

	std::cout << "Size: "
			  << mstack.size() << std::endl;

	std::cout << "\n========================================\n";
	std::cout << "TEST 8: Compare with std::list" << std::endl;
	std::cout << "========================================\n";
	
	MutantStack<int> ms;
	std::list<int> lst;
	
	// Add identical values
	ms.push(5);
	ms.push(17);
	ms.push(3);
	ms.push(5);
	ms.push(737);
	ms.push(0);
	
	lst.push_back(5);
	lst.push_back(17);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	
	// MutantStack
	std::cout << "MutantStack contents:" << std::endl;
	
	for (MutantStack<int>::iterator it = ms.begin();
		it != ms.end(); ++it)
	{
		std::cout << "  " << *it << std::endl;
	}
	
	// std::list
	std::cout << "\nstd::list contents:" << std::endl;
	
	for (std::list<int>::iterator it = lst.begin();
		it != lst.end(); ++it)
	{
		std::cout << "  " << *it << std::endl;
	}


	printHeader("ALL TESTS FINISHED");

	return (0);
}