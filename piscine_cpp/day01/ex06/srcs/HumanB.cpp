#include "HumanB.hpp"

/**
 * Constructor(s) & Destructor(s)
 */

HumanB::HumanB(std::string const &name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

/*
 * Public method(s)
 */

void	HumanB::attack(void) const
{
	std::cout << (*this)._name << " attacks with his " << ((*this)._weapon == NULL ? "punch" : (*((*this)._weapon)).getType()) << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	(*this)._weapon = &weapon;
	//std::cout << &weapon << std::endl; //TEST
}

/*
 * Private method(s)
 */
