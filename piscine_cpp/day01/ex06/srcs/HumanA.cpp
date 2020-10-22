#include "HumanA.hpp"

/**
 * Constructor(s) & Destructor(s)
 */

HumanA::HumanA(std::string const &name, Weapon const &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}

/*
 * Public method(s)
 */

void	HumanA::attack(void) const
{
	std::cout << (*this)._name << " attacks with his " << (*this)._weapon.getType() << std::endl;
}

/*
 * Private method(s)
 */
