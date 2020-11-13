#include "Enemy.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Enemy::Enemy(void) : _hp(0), _type("default")
{
	std::cout << "<Enemy> Default constructor called" << std::endl;
}

Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
	std::cout << "<Enemy> Constructor called" << std::endl;
}

Enemy::Enemy(Enemy const &src)
{
	std::cout << "<Enemy> Copy constructor called" << std::endl;
	*this = src;
}

Enemy::~Enemy()
{
	std::cout << "<Enemy> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

Enemy			&Enemy::operator=(Enemy const &rhs)
{
	std::cout << "<Enemy> Assignement operator called" << std::endl;
	(*this)._hp = rhs.getHP();
	(*this)._type = rhs.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Enemy const &rhs)
{
	o << "| HP: " << rhs.getHP() << std::endl;
	o << "| Type: " << rhs.getType() << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&Enemy::getType(void) const
{
	return ((*this)._type);
}

int					Enemy::getHP(void) const
{
	return ((*this)._hp);
}

void				Enemy::takeDamage(int amount)
{
	if ((*this)._hp > 0 && !(amount < 0))
	{
		(*this)._hp = (*this)._hp > amount ? (*this)._hp - amount : 0;
		std::cout << (*this)._type << " has taken " << amount << " points of damage!" << std::endl;
	}
}

/**
 * Private method(s)
 */

