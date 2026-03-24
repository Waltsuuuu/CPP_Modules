#include "Form.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
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