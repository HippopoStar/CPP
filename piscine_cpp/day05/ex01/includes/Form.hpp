#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{

	public:

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

		Form(std::string const &name, int grade);
		Form(Form const &src);
		~Form(void);

		Form		&operator=(Form const &rhs);
		bool			getIsSigned(void) const;
		std::string const	&getName(void) const;
		int			getRequieredGrade(void) const;
		void			beSigned(Bureaucrat const &b);

	private:
		Form(void);

		bool				_is_signed;
		std::string const		_name;
		int const			_requiered_grade;

};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
