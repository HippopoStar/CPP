#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <cstdio>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
		virtual void		execute(Bureaucrat const &executor) const;
		std::string const	&getTarget(void) const;
		int			getExecutionGrade(void) const;

	private:

		ShrubberyCreationForm(void);

		std::string	_target;
		int		_execution_grade;

};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);

#endif
