#include "AssaultTerminator.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src)
{
	std::cout << "<AssaultTerminator> Copy constructor called" << std::endl;
	*this = src;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I'll be back ..." << std::endl;
}

/**
 * Operator overload(s)
 */

AssaultTerminator		&AssaultTerminator::operator=(AssaultTerminator const &rhs)
{
	std::cout << "<AssaultTerminator> Assignement operator called" << std::endl;
	(void)rhs;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, AssaultTerminator const &rhs)
{
	o << "<AssaultTerminator> \"<<\" operator called" << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

ISpaceMarine	*AssaultTerminator::clone(void) const
{
	ISpaceMarine	*clone;

	clone = new AssaultTerminator(*this);
	return (clone);
}

void			AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. Purify it!" << std::endl;
}

void			AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
}

void			AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with a chainfists *" << std::endl;
}

/**
 * Private method(s)
 */

