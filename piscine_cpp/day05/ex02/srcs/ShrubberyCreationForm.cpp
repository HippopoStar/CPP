#include "ShrubberyCreationForm.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 150), _target("default"), _execution_grade(150)
{
	std::cout << "<ShrubberyCreationForm> Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145), _target(target), _execution_grade(137)
{
	std::cout << "<ShrubberyCreationForm> Constructor called with parameter [\"" << target << "\"]" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src), _target(src.getTarget()), _execution_grade(src.getExecutionGrade())
{
	std::cout << "<ShrubberyCreationForm> Copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "<ShrubberyCreationForm> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "<ShrubberyCreationForm> Assignement operator called" << std::endl;
	//(*this)._is_signed = rhs.getIsSigned();
	//(*this)._name = rhs.getName();
	//(*this)._requiered_grade = rhs.getRequieredGrade();
	(*this)._target = rhs.getTarget();
	(*this)._execution_grade = rhs.getExecutionGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs)
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

std::string const	&ShrubberyCreationForm::getTarget(void) const
{
	return ((*this)._target);
}

int			ShrubberyCreationForm::getExecutionGrade(void) const
{
	return ((*this)._execution_grade);
}

void			ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	FILE	*f;

	if (!((*this).getIsSigned()))
	{
		std::cout << "ShrubberyCreationForm targetting \"" << (*this).getTarget() << "\" must first be signed!" << std::endl;
	}
	else if (executor.getGrade() > (*this)._execution_grade)
	{
		throw GradeTooLowException();
	}
	else
	{
		if ((f = fopen((*this).getTarget().c_str(), "w"))  == NULL)
		{
			std::cout << "An error occured while trying to open \"" << (*this).getTarget() << "\" file" << std::endl;
		}
		else
		{
			fputs("test\n", f);
			fclose(f);
			std::cout << "ShrubberyCreationForm targetting \"" << (*this).getTarget() << "\" executed by " << executor.getName() << std::endl;
		}
	}
}

/**
 * Private method(s)
 */

