#include "Character.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Character::Character(void) : _name("default"), _inventory({ NULL, NULL, NULL, NULL })
{
	std::cout << "<Character> Default constructor called" << std::endl;
}

Character::Character(Character const &src)
{
	std::cout << "<Character> Copy constructor called" << std::endl;
	*this = src;
}

Character::~Character(void)
{
	std::cout << "<Character> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

Character		&Character::operator=(Character const &rhs)
{
	std::cout << "<Character> Assignement operator called" << std::endl;
	(*this)._name = rhs.getName();
	(*this)._inventory[0] = rhs.getInventory()[0];
	(*this)._inventory[1] = rhs.getInventory()[1];
	(*this)._inventory[2] = rhs.getInventory()[2];
	(*this)._inventory[3] = rhs.getInventory()[3];
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Character const &rhs)
{
	o << "<Character> operator \"<<\" called" << std::endl;
	o << "| Name: " << rhs.getName() << std::endl;
	o << "| Inventory:" << std::endl;
	o << "|\t" << rhs.getInventory()[0].getType() << std::endl;
	o << "|\t" << rhs.getInventory()[1].getType() << std::endl;
	o << "|\t" << rhs.getInventory()[2].getType() << std::endl;
	o << "|\t" << rhs.getInventory()[3].getType() << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&Character::getName(void) const
{
	return ((*this)._name);
}

AMateria			*[4]Character::getInventory(void) const
{
	return ((*this)._inventory);
}

void				equip(AMateria *m)
{
	int		i;

	i = 0;
	while (i < 4 && !((*this)._inventory[i] == NULL))
	{
		i++;
	}
	if (i < 4)
	{
		(*this)._inventory[i] = m;
	}
}

void				unequip(int idx)
{
	if (0 <= idx && idx < 4)
	{
		(*this)._inventory[idx] = NULL;
	}
}

void				use(int idx, ICharacter &target)
{
	if (0 <= idx && idx < 4 && !((*this)._inventory[idx] == NULL))
	{
		(*this)._inventory[idx].use(target);
	}
}

/**
 * Private method(s)
 */

