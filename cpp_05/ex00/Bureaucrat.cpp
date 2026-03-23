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

// --- Member Functions ---

const std::string Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::incrementGrade()  {
	_grade++;
	if (_grade > 150) {
		throw GradeTooHighException();
	}
}

void	Bureaucrat::decrementGrade() {
	_grade--;
	if (_grade < 1) {
		throw GradeTooLowException();
	}
}

// --- Exceptions --- 

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("Bureacrat grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("Bureacrat grade is too low");
}

// --- Insertion Operator Overload ---
std::ostream& operator << (std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureacrat grade " << bureaucrat.getGrade();
	return out;
}