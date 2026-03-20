#include "Bureaucrat.hpp"
#include <string>

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1) {
		throw GradeTooHighException();
	}
	if (_grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade){
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

