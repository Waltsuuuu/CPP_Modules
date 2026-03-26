#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

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