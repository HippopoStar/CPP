#include "PowerFist.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{
	std::cout << "<PowerFist> Default constructor called" << std::endl;
}

PowerFist::PowerFist(PowerFist const &src) : AWeapon(src)
{
	std::cout << "<PowerFist> Copy constructor called" << std::endl;
	*this = src;
}

PowerFist::~PowerFist()
{
	std::cout << "<PowerFist> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

PowerFist		&PowerFist::operator=(PowerFist const &rhs)
{
	std::cout << "<PowerFist> Assignement operator called" << std::endl;
	(*this)._name = rhs.getName();
	(*this)._apcost = rhs.getAPCost();
	(*this)._damage = rhs.getDamage();
	return (*this);
}

/*
**std::ostream	&operator<<(std::ostream &o, PowerFist const &rhs)
**{
**	o << "| Name: " << rhs.getName() << std::endl;
**	o << "| APCost: " << rhs.getAPCost() << std::endl;
**	o << "| Damage: " << rhs.getDamage() << std::endl;
**	return (o);
**}
*/

/**
 * Public method(s)
 */

void		PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

/**
 * Private method(s)
 */

