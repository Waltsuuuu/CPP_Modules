#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1) {
		throw GradeTooHighException();
	}
	if (_grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat() {
}