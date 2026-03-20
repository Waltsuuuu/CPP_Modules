#ifndef BUREAUCRAT_HPP
#  define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		int					grade; // 1 = Highest, 150 = Lowest.
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator = (const Bureaucrat& other);
		~Bureaucrat();

		std::string getName();
		void		setName();
		void		incrementGrade();
		void		decrementGrade();
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& Bureaucrat);

#endif