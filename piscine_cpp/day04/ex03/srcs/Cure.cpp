#include "Cure.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "<Cure> Default constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
	std::cout << "<Cure> Copy constructor called" << std::endl;
	*this = src;
}

Cure::~Cure(void)
{
	std::cout << "<Cure> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

Cure			&Cure::operator=(Cure const &rhs)
{
	std::cout << "<Cure> Assignement operator called" << std::endl;
	(void)rhs;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Cure const &rhs)
{
	o << "<Cure> operator \"<<\" called" << std::endl;
	(void)rhs;
	return (o);
}

/**
 * Public method(s)
 */

/*
**std::string const	&Ice::getType(void) const
**{
**	return ((*this)._type);
**}
**
**unsigned int		Ice::getXP(void) const
**{
**	return ((*this)._xp);
**}
*/

AMateria			*Cure::clone(void) const
{
	AMateria	*clone;

	clone = new Cure(*this);
	return (clone);
}

void				Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	AMateria::use(target);
}

/**
 * Private method(s)
 */

