#include "RobotomyRequestForm.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 150), _target("default"), _execution_grade(150)
{
	std::cout << "<RobotomyRequestForm> Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("RobotomyRequestForm", 145), _target(target), _execution_grade(137)
{
	std::cout << "<RobotomyRequestForm> Constructor called with parameter [\"" << target << "\"]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src), _target(src.getTarget()), _execution_grade(src.getExecutionGrade())
{
	std::cout << "<RobotomyRequestForm> Copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "<RobotomyRequestForm> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "<RobotomyRequestForm> Assignement operator called" << std::endl;
	//(*this)._is_signed = rhs.getIsSigned();
	//(*this)._name = rhs.getName();
	//(*this)._requiered_grade = rhs.getRequieredGrade();
	(*this)._target = rhs.getTarget();
	(*this)._execution_grade = rhs.getExecutionGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs)
{
	o << "| Is Signed: " << rhs.getIsSigned() << std::endl;
	o << "| Name: " << rhs.getName() << std::endl;
	o << "| Requiered Grade: " << rhs.getRequieredGrade() << std::endl;
	o << "| Target: " << rhs.getTarget() << std::endl;
	o << "| Execution Grade: " << rhs.getExecutionGrade() << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&RobotomyRequestForm::getTarget(void) const
{
	return ((*this)._target);
}

int			RobotomyRequestForm::getExecutionGrade(void) const
{
	return ((*this)._execution_grade);
}

void			RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	FILE	*f;

	if (!((*this).getIsSigned()))
	{
		std::cout << "RobotomyRequestForm targetting \"" << (*this).getTarget() << "\" must first be signed!" << std::endl;
	}
	else if (executor.getGrade() > (*this)._execution_grade)
	{
		throw GradeTooLowException();
	}
	else
	{
		std::cout << "* BRRR! BRRR! BRRR! ... * - <" << (*this)._target << "> has been robotomized" << std::endl;
	}
}

/**
 * Private method(s)
 */

