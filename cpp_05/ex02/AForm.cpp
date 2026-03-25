#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToExecute > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& copy)
	: _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {
}

AForm& AForm::operator = (const AForm& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm() {
}

// --- Member functions ---

const std::string AForm::getName() const {
	return (_name);
}

bool AForm::getIsSigned() const {
	return (_isSigned);
}

int AForm::getGradeToSign() const {
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	if (this->_isSigned) {
		throw AForm::AlreadySignedException();
	}
	this->_isSigned = true;
}

// --- Exceptions ---

const char* AForm::GradeTooLowException::what() const noexcept {
	return ("grade too low!");
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return ("grade too high!");
}

const char* AForm::AlreadySignedException::what() const noexcept {
	return ("form already signed");
}

const char* AForm::FormNotSignedException::what() const noexcept {
	return ("form not signed");
}

// --- Insertion Operator Overload ---

std::ostream& operator << (std::ostream& out, const AForm& AForm) {
	out << "AForm: " << AForm.getName() << std::endl
		<< "Grade to sign: " << AForm.getGradeToSign() << std::endl
		<< "Grade to execute: " << AForm.getGradeToExecute() << std::endl;
	if (AForm.getIsSigned())
		out << "Signed: Yes" << std::endl;
	else
		out << "Signed: No" << std::endl;
	return (out);
}