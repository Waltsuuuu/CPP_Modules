#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Bureaucrat;

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
		bool				getIsSigned()		const;
		int					getGradeToSign()	const;
		int					getGradeToExecute()	const;
		void				beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class AlreadySignedException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator << (std::ostream& out, const Form& form);

#endif