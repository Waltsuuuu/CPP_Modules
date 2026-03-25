#ifndef AForm_HPP
# define AForm_HPP

# include <string>

class	Bureaucrat;

class AForm {
  private:
	const std::string	_name;
	bool 				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

  public:
	AForm(const std::string name, const int _gradeToSign,
		const int _gradeToExecute);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	virtual void		execute(Bureaucrat const & executor) const = 0;
	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
		public:
		const char *what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
		public:
		const char *what() const noexcept override;
	};

	class AlreadySignedException : public std::exception {
		public:
		const char *what() const noexcept override;
	};

	class FormNotSignedException : public std::exception {
		public:
			const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif