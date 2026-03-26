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
	if (_grade <= 1) {
		throw GradeTooHighException();
	}
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade >= 150) {
		throw GradeTooLowException();
	}
	_grade++;
}

void	Bureaucrat::signAForm(AForm& AForm) {
	try {
		AForm.beSigned(*this);  // may throw GradeTooLowException / AlreadSignedException
		std::cout << _name << " signed " << AForm.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn’t sign "
		          << AForm.getName()
		          << " because " << e.what()
		          << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn’t execute "
		          << form.getName()
		          << " because " << e.what()
		          << std::endl;
	}
}

// --- Exceptions --- 

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("Bureaucrat grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("Bureaucrat grade is too low");
}

// --- Insertion Operator Overload ---
std::ostream& operator << (std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}