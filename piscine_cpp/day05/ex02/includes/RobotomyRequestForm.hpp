#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdio>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
		virtual void		execute(Bureaucrat const &executor) const;
		std::string const	&getTarget(void) const;
		int			getExecutionGrade(void) const;

	private:

		RobotomyRequestForm(void);

		std::string	_target;
		int		_execution_grade;

};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs);

#endif
