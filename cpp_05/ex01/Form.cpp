#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& copy)
	: _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
}

Form& Form::operator = (const Form& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form() {
}

// --- Member functions ---

const std::string Form::getName() const {
	return (_name);
}

bool Form::getIsSigned() const {
	return (_isSigned);
}

int Form::getGradeToSign() const {
	return (_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (_gradeToExecute);
}

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeToSign()) {
		std::cout	<< bureaucrat.getName() << " couldn't sign " 
					<< this->getName() 		<< " because their grade is too low.\n";
		throw Form::GradeTooLowException();
	}
	if (this->_isSigned) {
		std::cout	<< bureaucrat.getName() << " couldn't sign " 
					<< this->getName() 		<< " because it already contains a signature.\n";
		return;
	}
	this->_isSigned = true;
	std::cout	<< bureaucrat.getName() << " signed " << this->getName() << std::endl;
}

// --- Exceptions ---

const char* Form::GradeTooLowException::what() const noexcept {
	return ("Grade too low!");
}

const char* Form::GradeTooHighException::what() const noexcept {
	return ("Grade too high!");
}