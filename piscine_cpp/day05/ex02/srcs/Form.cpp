#include "Form.hpp"

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat's grade not low enough to sign form");
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat's grad not high enough to sign form");
}

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Form::Form(void) : _is_signed(false), _name("default"), _requiered_grade(150)
{
	std::cout << "<Form> Default constructor called" << std::endl;
}

Form::Form(std::string const &name, int requiered_grade) : _is_signed(false), _name(name), _requiered_grade(requiered_grade)
{
	std::cout << "<Form> Constructor called with parameters [\"" << name << "\"] and [" << requiered_grade << "]" << std::endl;
	if (!(0 < requiered_grade && requiered_grade < 151))
	{
		if (requiered_grade < 1)
		{
			throw GradeTooHighException();
		}
		else
		{
			throw GradeTooLowException();
		}
	}
}

Form::Form(Form const &src) : _is_signed(src.getIsSigned()), _name(src.getName()), _requiered_grade(src.getRequieredGrade())
{
	std::cout << "<Form> Copy constructor called" << std::endl;
	*this = src;
}

Form::~Form(void)
{
	std::cout << "<Form> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

Form			&Form::operator=(Form const &rhs)
{
	std::cout << "<Form> Assignement operator called" << std::endl;
	(*this)._is_signed = rhs.getIsSigned();
	//(*this)._name = rhs.getName();
	//(*this)._requiered_grade = rhs.getRequieredGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << "| Is Signed: " << rhs.getIsSigned() << std::endl;
	o << "| Name: " << rhs.getName() << std::endl;
	o << "| Requiered Grade: " << rhs.getRequieredGrade() << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

bool			Form::getIsSigned(void) const
{
	return ((*this)._is_signed);
}

std::string const	&Form::getName(void) const
{
	return ((*this)._name);
}

int			Form::getRequieredGrade(void) const
{
	return ((*this)._requiered_grade);
}

void			Form::beSigned(Bureaucrat const &b)
{
	b.signForm(*this);
	if (b.getGrade() <= (*this)._requiered_grade)
	{
		(*this)._is_signed = true;
	}
}

void			Form::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << "<" << (*this).getName() << "> executed" << std::endl;
}

/**
 * Private method(s)
 */

