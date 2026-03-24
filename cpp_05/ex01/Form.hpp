#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		Form(const std::string name, const int _gradeToSign, const int _gradeToExecute);
		Form(const Form& copy);
		Form& operator = (const Form& other);
		~Form();

		const std::string	getName()			const;
		const bool			getIsSigned()		const;
		const int			getGradeToSign()	const;
		const int			getGradeToExecute()	const;
		void				beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

#endif