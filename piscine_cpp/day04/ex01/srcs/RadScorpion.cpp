#include "RadScorpion.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &src) : Enemy(src)
{
	std::cout << "<RadScorpion> Copy constructor called" << std::endl;
	*this = src;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

/**
 * Operator overload(s)
 */

RadScorpion		&RadScorpion::operator=(RadScorpion const &rhs)
{
	std::cout << "<RadScorpion> Assignement operator called" << std::endl;
	(*this)._hp = rhs.getHP();
	(*this)._type = rhs.getType();
	return (*this);
}

/*
**std::ostream	&operator<<(std::ostream &o, RadScorpion const &rhs)
**{
**	o << "| HP: " << rhs.getHP() << std::endl;
**	o << "| Type: " << rhs.getType() << std::endl;
**	return (o);
**}
*/

/**
 * Public method(s)
 */

void		RadScorpion::takeDamage(int amount)
{
	(*((Enemy *)this)).takeDamage(amount);
}

/**
 * Private method(s)
 */

