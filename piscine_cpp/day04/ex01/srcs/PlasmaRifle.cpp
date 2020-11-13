#include "PlasmaRifle.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21)
{
	std::cout << "<PlasmaRifle> Default constructor called" << std::endl;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) : AWeapon(src)
{
	std::cout << "<PlasmaRifle> Copy constructor called" << std::endl;
	*this = src;
}

PlasmaRifle::~PlasmaRifle()
{
	std::cout << "<PlasmaRifle> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

PlasmaRifle	&PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
	std::cout << "<PlasmaRifle> Assignement operator called" << std::endl;
	(*this)._name = rhs.getName();
	(*this)._apcost = rhs.getAPCost();
	(*this)._damage = rhs.getDamage();
	return (*this);
}

/*
**std::ostream	&operator<<(std::ostream &o, PlasmaRifle const &rhs)
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

void		PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

/**
 * Private method(s)
 */

