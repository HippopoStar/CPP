#include "Bureaucrat.hpp"

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade can not be higher than 1");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade can not be lower than 150");
}

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
	std::cout << "<Bureaucrat> Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	std::cout << "<Bureaucrat> Constructor called with parameters [\"" << name << "\"] and [" << grade << "]" << std::endl;
	if (!(0 < grade && grade < 151))
	{
		if (grade < 1)
		{
			throw GradeTooHighException();
		}
		else
		{
			throw GradeTooLowException();
		}
		(*this)._grade = 150;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "<Bureaucrat> Copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "<Bureaucrat> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "<Bureaucrat> Assignement operator called" << std::endl;
	//(*this)._name = rhs.getName();
	(*this)._grade = rhs.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << "<" << rhs.getName() << ">, bureaucrat grade <" << rhs.getGrade() << ">" << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&Bureaucrat::getName(void) const
{
	return ((*this)._name);
}

int			Bureaucrat::getGrade(void) const
{
	return ((*this)._grade);
}

void			Bureaucrat::incrementGrade(void)
{
	if (!((*this)._grade > 1))
	{
		throw GradeTooHighException();
	}
	else
	{
		((*this)._grade)--;
	}
}

void			Bureaucrat::decrementGrade(void)
{
	if (!((*this)._grade < 150))
	{
		throw GradeTooLowException();
	}
	else
	{
		((*this)._grade)++;
	}
}

void			Bureaucrat::signForm(Form &f) const
{
	if (f.getRequieredGrade() < (*this)._grade || f.getIsSigned() == true)
	{
		std::cout << "Bureaucrat <" << (*this)._name << "> can't sign form <" << f.getName() << "> because ";
		if (f.getRequieredGrade() < (*this)._grade)
		{
			std::cout << "of insufficient grade" << std::endl;
			throw Form::GradeTooLowException();
		}
		else
		{
			std::cout << "it is signed already" <<std::endl;
		}
	}
	else
	{
		std::cout << "Bureaucrat <" << (*this)._name << "> signs form <" << f.getName() << ">" << std::endl;
		f.beSigned(*this);
	}
}

/**
 * Private method(s)
 */

