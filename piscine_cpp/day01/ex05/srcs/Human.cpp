#include "Human.hpp"

/**
 * Constructor(s) & Destructor(s)
 */

Human::Human(void) : _nut((*this)._gather_brain())
{
}

Human::~Human(void)
{
}

/**
 * Public method(s)
 */

std::string	Human::identify(void) const
{
	return ((*this)._nut.identify());
}

const Brain	&Human::getBrain(void) const
{
	Brain const	&nut_ref = (*this)._nut;

	return (nut_ref);
}

/**
 * Private method(s)
 */

Brain	Human::_gather_brain(void)
{
	Brain	brain;

	return (brain);
}
