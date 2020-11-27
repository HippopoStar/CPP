#include "Ice.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Ice::Ice(void) : _type("ice"), _xp(0)
{
	std::cout << "<Ice> Default constructor called" << std::endl;
}

Ice::Ice(Ice const &src)
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
	(*this)._xp = rhs.getXP();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Ice const &rhs)
{
	o << "<Ice> operator \"<<\" called" << std::endl;
	o << "| Type: " << (*this)._type << std::endl;
	o << "| XP: " << (*this)._xp << std::endl;
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

AMateria			*clone(void) const
{
	AMateria	*clone;

	clone = new Ice(*this);
	return (clone);
}

void				Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	(*this)._xp = (*this)._xp + 10;
}

/**
 * Private method(s)
 */

