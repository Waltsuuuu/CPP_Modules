#ifndef BUREAUCRAT_HPP
#  define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade; // 1 = Highest, 150 = Lowest.
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator = (const Bureaucrat& other);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form& form);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

};

std::ostream& operator << (std::ostream& out, const Bureaucrat& bureaucrat);

#endif