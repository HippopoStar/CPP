#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class	Bureaucrat
{

	class	GradeTooHighException : public std::exception
	{
		public:
			virtual char const	*what(void) const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			virtual char const	*what(void) const throw();
	};

	public:
		Bureaucrat(std::string const &name, int grade) /*throw(GradeTooHighException, GradeTooLowException)*/;
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat		&operator=(Bureaucrat const &rhs);
		std::string const	&getName(void) const;
		int			getGrade(void) const;
		void			incrementGrade(void) /*throw(GradeTooHighException)*/;
		void			decrementGrade(void) /*throw(GradeTooLowException)*/;

	private:
		Bureaucrat(void);

		std::string const		_name;
		int				_grade;

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
