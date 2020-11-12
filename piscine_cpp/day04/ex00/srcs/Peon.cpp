#include "Victim.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Peon::Peon(void) : Victim()
{
	std::cout << "Default constructor called" << std::endl;
}

Peon::Peon(std::string const &name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) : Victim(src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

/**
 * Operator overload(s)
 */

Peon			&Peon::operator=(Peon const &rhs)
{
	std::cout << "Assignement operator called" << std::endl;
	(*this)._name = rhs.getName();
	return (*this);
}

/**
 * Public method(s)
 */

void				Peon::getPolymorphed(void) const
{
	std::cout << (*this)._name << " was just polymorphed into a pink pony!" << std::endl;
}

/**
 * Private method(s)
 */

