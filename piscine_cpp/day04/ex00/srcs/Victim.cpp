#include "Victim.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Victim::Victim(void) : _name("default")
{
	std::cout << "Default constructor called" << std::endl;
}

Victim::Victim(std::string const &name) : _name(name)
{
	std::cout << "A random victim called " << name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Victim::~Victim()
{
	std::cout << "The victim " << (*this)._name << " died for no apparent reasons!" << std::endl;
}

/**
 * Operator overload(s)
 */

Victim			&Victim::operator=(Victim const &rhs)
{
	std::cout << "Assignement operator called" << std::endl;
	(*this)._name = rhs.getName();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Victim const &rhs)
{
	o << "I'm " << rhs.getName() << " and I like otters!" << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&Victim::getName(void) const
{
	return ((*this)._name);
}

void				Victim::getPolymorphed(void) const
{
	std::cout << (*this)._name << " was just polymorphed in a cute little sheep!" << std::endl;
}

/**
 * Private method(s)
 */

