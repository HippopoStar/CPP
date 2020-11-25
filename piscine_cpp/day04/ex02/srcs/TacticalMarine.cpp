#include "TacticalMarine.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for action!" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &src)
{
	std::cout << "<TacticalMarine> Copy constructor called" << std::endl;
	*this = src;
}

TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh ..." << std::endl;
}

/**
 * Operator overload(s)
 */

TacticalMarine		&TacticalMarine::operator=(TacticalMarine const &rhs)
{
	std::cout << "<TacticalMarine> Assignement operator called" << std::endl;
	(void)rhs;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, TacticalMarine const &rhs)
{
	o << "<TacticalMarine> \"<<\" operator called" << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

ISpaceMarine	*TacticalMarine::clone(void) const
{
	ISpaceMarine	*clone;

	clone = new TacticalMarine(*this);
	return (clone);
}

void			TacticalMarine::battleCry(void) const
{
	std::cout << "For the Holy PLOT!" << std::endl;
}

void			TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void			TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}

/**
 * Private method(s)
 */

