#include "AWeapon.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

AWeapon::AWeapon(void) : _name("default"), _apcost(0), _damage(0)
{
	std::cout << "<AWeapon> Default constructor called" << std::endl;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage)
{
	std::cout << "<AWeapon> Constructor called" << std::endl;
}

AWeapon::AWeapon(AWeapon const &src)
{
	std::cout << "<AWeapon> Copy constructor called" << std::endl;
	*this = src;
}

AWeapon::~AWeapon()
{
	std::cout << "<AWeapon> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

AWeapon			&AWeapon::operator=(AWeapon const &rhs)
{
	std::cout << "<AWeapon> Assignement operator called" << std::endl;
	(*this)._name = rhs.getName();
	(*this)._apcost = rhs.getAPCost();
	(*this)._damage = rhs.getDamage();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, AWeapon const &rhs)
{
	o << "| Name: " << rhs.getName() << std::endl;
	o << "| APCost: " << rhs.getAPCost() << std::endl;
	o << "| Damage: " << rhs.getDamage() << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&AWeapon::getName(void) const
{
	return ((*this)._name);
}

int					AWeapon::getAPCost(void) const
{
	return ((*this)._apcost);
}

int					AWeapon::getDamage(void) const
{
	return ((*this)._damage);
}

/**
 * Private method(s)
 */

