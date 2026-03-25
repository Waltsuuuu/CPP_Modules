#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm",
	145, 137) {
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
	_target = copy._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

// --- Exceptions ---
const char* ShrubberyCreationForm::FileCreationError::what() const noexcept {
	return ("Could not open file.");
}


// --- Member functions ---

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();
	
	std::ofstream outfile(_target + "_shrubbery");
	if (!outfile.is_open())
		throw FileCreationError();
	
	outfile
	<< "       /\\\n"
	<< "      /**\\\n"
	<< "     /****\\\n"
	<< "    /******\\\n"
	<< "   /********\\\n"
	<< "      ||||\n"
	<< "      ||||\n";

	outfile.close();
	std::cout << "Shrubbery created into " << _target + "_shrubbery" << std::endl;
}
