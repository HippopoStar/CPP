#include "PresidentialPardonForm.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 150), _target("default"), _execution_grade(150)
{
	std::cout << "<PresidentialPardonForm> Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("PresidentialPardonForm", 145), _target(target), _execution_grade(137)
{
	std::cout << "<PresidentialPardonForm> Constructor called with parameter [\"" << target << "\"]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src), _target(src.getTarget()), _execution_grade(src.getExecutionGrade())
{
	std::cout << "<PresidentialPardonForm> Copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "<PresidentialPardonForm> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

PresidentialPardonForm		&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "<PresidentialPardonForm> Assignement operator called" << std::endl;
	//(*this)._is_signed = rhs.getIsSigned();
	//(*this)._name = rhs.getName();
	//(*this)._requiered_grade = rhs.getRequieredGrade();
	(*this)._target = rhs.getTarget();
	(*this)._execution_grade = rhs.getExecutionGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs)
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

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	return ((*this)._target);
}

int			PresidentialPardonForm::getExecutionGrade(void) const
{
	return ((*this)._execution_grade);
}

void			PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	FILE	*f;

	if (!((*this).getIsSigned()))
	{
		std::cout << "PresidentialPardonForm targetting \"" << (*this).getTarget() << "\" must first be signed!" << std::endl;
	}
	else if (executor.getGrade() > (*this)._execution_grade)
	{
		throw GradeTooLowException();
	}
	else
	{
		std::cout << "<" << (*this)._target << "> has been forgiven by Zafod Beeblebrox" << std::endl;
	}
}

/**
 * Private method(s)
 */

