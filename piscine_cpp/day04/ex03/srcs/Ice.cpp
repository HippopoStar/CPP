#include "Ice.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "<Ice> Default constructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
	std::cout << "<Ice> Copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice(void)
{
	std::cout << "<Ice> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

Ice				&Ice::operator=(Ice const &rhs)
{
	std::cout << "<Ice> Assignement operator called" << std::endl;
	(void)rhs;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Ice const &rhs)
{
	o << "<Ice> operator \"<<\" called" << std::endl;
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

AMateria			*Ice::clone(void) const
{
	AMateria	*clone;

	clone = new Ice(*this);
	return (clone);
}

void				Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}

/**
 * Private method(s)
 */

