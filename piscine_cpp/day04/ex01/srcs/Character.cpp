#include "Character.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Character::Character(void) : _name("default), _ap(0), _weapon(NULL)
{
	std::cout << "<Character> Default constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name), _ap(40), _weapon(NULL)
{
	std::cout << "<Character> Constructor called" << std::endl;
}

Character::Character(Character const &src)
{
	std::cout << "<Character> Copy constructor called" << std::endl;
	*this = src;
}

Character::~Character()
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
	(*this)._ap = rhs.getAP();
	(*this)._weapon = rhs.getWeapon();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Character const &rhs)
{
	o << rhs.getName() << " has " << rhs.getAP() << " AP";
	if (rhs.getWeapon() == NULL)
	{
		o << " and is unarmed";
	}
	else
	{
		o << " and carries a " << rhs.getWeapon().getName();
	{
	o << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&Character::getName(void) const
{
	return ((*this)._name);
}

int					Character::getAP(void) const
{
	return ((*this)._ap);
}

AWeapon const		*Character::getWeapon(void) const
{
	return ((*this)._weapon);
}

void				Character::recoverAP(void)
{
	if ((*this)._ap + 10 > 40)
	{
		(*this)._ap = 40;
	}
	else
	{
		(*this)._ap = (*this)._ap + 10;
	{
	std::cout << (*this)._name << " recovers 10 AP!" << std::endl;
}

void				Character::attack(Enemy *enemy)
{
	if (enemy)
	{
		if (!(*this)._weapon)
		{
			(*this)._name << " wishes to attack but has no weapon!" << std::endl;
		}
		else
		{
			if ((*this)._ap < (*this)._weapon->getAPCost())
			{
				(*this)._name << " wishes to attack but has no more AP!" << std::endl;
			}
			else
			{
				std::cout << (*this)._name << " attacks " << enemy->getType() << " with a " << (*this)._weapon->getName() << std::endl;
				(*this)._weapon->attack();
				enemy.takeDamage((*this)._weapon->getDamage());
				(*this)._ap = (*this)._ap - (*this)._weapon->getAPCost();
				if (enemy.getHP() == 0)
				{
					delete enemy; //TODO: ne va-t'on pas avoir un probleme etant donne le manque de feedback?
				}
			}
		}
	}
}

/*
** Remettre l'arme a NULL ne pose pas de probleme particulier
*/
void				Character::equip(AWeapon *weapon)
{
	(*this)._weapon = weapon;
}

/**
 * Private method(s)
 */

