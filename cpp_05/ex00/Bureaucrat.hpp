#ifndef BUREAUCRAT_HPP
#  define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade; // 1 = Highest, 150 = Lowest.
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator = (const Bureaucrat& other);
		~Bureaucrat();

		std::string getName();
		void		setName();
		void		incrementGrade();
		void		decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Bureacrat grade is too high");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Bureaucrat grade is too low");
				}
		};

};

std::ostream& operator << (std::ostream& out, const Bureaucrat& Bureaucrat);

#endif