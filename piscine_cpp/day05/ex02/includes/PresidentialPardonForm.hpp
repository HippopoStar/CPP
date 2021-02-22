#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <cstdio>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	PresidentialPardonForm : public Form
{

	public:

		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
		virtual void		execute(Bureaucrat const &executor) const;
		std::string const	&getTarget(void) const;
		int			getExecutionGrade(void) const;

	private:

		PresidentialPardonForm(void);

		std::string	_target;
		int		_execution_grade;

};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif
