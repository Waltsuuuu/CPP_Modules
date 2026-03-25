#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: Form("ShrubberyCreationForm", 145, 137) {
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) 
	: Form(copy) {
	_target = copy._target;
} 

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& other) {
	if (this != &other) {
		Form::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

