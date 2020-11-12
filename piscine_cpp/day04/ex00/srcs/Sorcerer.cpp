#include "Sorcerer.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Sorcerer::Sorcerer(void) : _name("default"), _title("default")
{
	std::cout << "Default constructor called" << std::endl;
}

Sorcerer::Sorcerer(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Sorcerer::~Sorcerer()
{
	std::cout << (*this)._name << ", " << (*this)._title << ", is dead. Consequenses will never be the same!" << std::endl;
}

/**
 * Operator overload(s)
 */

Sorcerer	&Sorcerer::operator=(Sorcerer const &rhs)
{
	std::cout << "Assignement operator called" << std::endl;
	(*this)._name = rhs.getName();
	(*this)._title = rhs.getTitle();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Sorcerer const &rhs)
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies!" << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&Sorcerer::getName(void) const
{
	return ((*this)._name);
}

std::string const	&Sorcerer::getTitle(void) const
{
	return ((*this)._title);
}

void				Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

/**
 * Private method(s)
 */

