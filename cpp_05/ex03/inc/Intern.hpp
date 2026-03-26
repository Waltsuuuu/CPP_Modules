#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

// No unique characteristics.
// key ability: makeForm()
// 	- Params = 1. str name of a form, 2. str target of the form
//	- Return = Pointer to Aform object (corresponding to the form name passed as a parameter)
//				with its target initilized to the second parameter
class Intern {
	public:
		Intern();
		Intern(const Intern& copy) = delete;
		Intern& operator = (const Intern& other) = delete;
		~Intern();

		AForm* makeForm(std::string formName, std::string target);

		class InvalidFormException : public std::exception {
			const char* what() const noexcept override;
		};
};

#endif