#include "Zombie.hpp"

/**
 * Constructor(s) & Destructor(s)
 */

Zombie::Zombie(void) : _name(""), _type("")
{
	std::cout << "* A generic zombie appeared ! *" << std::endl;
}

Zombie::Zombie(std::string const &name, std::string const &type) : _name(name), _type(type)
{
	std::cout << "* A zombie <" << (*this)._name << " (" << (*this)._type << ")> appeared ! *" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "* Zombie <" << (*this)._name << " (" << (*this)._type << ")> passed away. *" << std::endl;
}

/**
 * Public method(s)
 */

void	Zombie::advert(void) const
{
	std::cout << "<" << (*this)._name << " (" << (*this)._type << ")> Braiiiiiiinnnssss ..." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << "<" << (*this)._name << " (" << (*this)._type << ")> Hello ! My name is " << (*this)._name << ", nice to meet you !" << std::endl;
}
