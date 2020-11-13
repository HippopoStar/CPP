#include "SuperMutant.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Break everything!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(src)
{
	std::cout << "<SuperMutant> Copy constructor called" << std::endl;
	*this = src;
}

SuperMutant::~SuperMutant()
{
	std::cout << "<SuperMutant> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

SuperMutant		&SuperMutant::operator=(SuperMutant const &rhs)
{
	std::cout << "<SuperMutant> Assignement operator called" << std::endl;
	(*this)._hp = rhs.getHP();
	(*this)._type = rhs.getType();
	return (*this);
}

/*
**std::ostream	&operator<<(std::ostream &o, SuperMutant const &rhs)
**{
**	o << "| HP: " << rhs.getHP() << std::endl;
**	o << "| Type: " << rhs.getType() << std::endl;
**	return (o);
**}
*/

/**
 * Public method(s)
 */

void		SuperMutant::takeDamage(int amount)
{
	(*((Enemy *)this)).takeDamage(amount - 3);
}

/**
 * Private method(s)
 */

