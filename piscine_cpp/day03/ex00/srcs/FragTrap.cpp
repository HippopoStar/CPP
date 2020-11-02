#include "FragTrap.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

FragTrap::FragTrap(void) : _hit_points(100), _max_hit_points(100), _energy_points(100), _max_energy_points(100), _level(1), _name("DefaultName"), \
				   _melee_attack_damage(30), _ranged_attack_damage(20), _armor_damage_reduction(5)
{
	std::cout << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : _hit_points(100), _max_hit_points(100), _energy_points(100), _max_energy_points(100), _level(1), _name(name), \
				   _melee_attack_damage(30), _ranged_attack_damage(20), _armor_damage_reduction(5)
{
	std::cout << "Constructor called with parameter \"" << name << "\"" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : _max_hit_points(100), _max_energy_points(100)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "Assignement operator called" << std::endl;
	(*this)._hit_points = rhs.getHitPoints();
	(*this)._energy_points = rhs.getEnergyPoints();
	(*this)._level = rhs.getLevel();
	(*this)._name = rhs.getName();
	(*this)._melee_attack_damage = rhs.getMeleeAttackDamage();
	(*this)._ranged_attack_damage = rhs.getRangedAttackDamage();
	(*this)._armor_damage_reduction = rhs.getArmorDamageReduction();
	return (*this);
}

/**
 * Public method(s)
 */

unsigned int		FragTrap::getHitPoints(void) const
{
	return ((*this)._hit_points);
}

unsigned int		FragTrap::getEnergyPoints(void) const
{
	return ((*this)._energy_points);
}

unsigned int		FragTrap::getLevel(void) const
{
	return ((*this)._level);
}

std::string const	&FragTrap::getName(void) const
{
	return ((*this)._name);
}

unsigned int		FragTrap::getMeleeAttackDamage(void) const
{
	return ((*this)._melee_attack_damage);
}

unsigned int		FragTrap::getRangedAttackDamage(void) const
{
	return ((*this)._ranged_attack_damage);
}

unsigned int		FragTrap::getArmorDamageReduction(void) const
{
	return ((*this)._armor_damage_reduction);
}

void			FragTrap::rangedAttack(std::string const &target) const
{
	/*
	std::cout << "FR4G-TP <" << (*this)._name << "> attacks <" << target.getName() << "> at range, causing ";
	std::cout << ((*this)._ranged_attack_damage < target.getArmorDamageReduction()) ? 0 : (*this)._ranged_attack_damage - target._getArmorDamageReduction();
	std::cout << " points of damage !" << std::endl;
	*/
	std::cout << "FR4G-TP <" << (*this)._name << "> attacks <" << target << "> at range" << std::endl;
}

void			FragTrap::meleeAttack(std::string const &target) const
{
	std::cout << "FR4G-TP <" << (*this)._name << "> attacks <" << target << "> at melee" << std::endl;
}

void			FragTrap::takeDamage(unsigned int const amount)
{
	unsigned int	resulting_damage;

	resulting_damage = (amount < (*this)._armor_damage_reduction) ? 0 : amount - (*this)._armor_damage_reduction;
	if (resulting_damage)
	{
		std::cout << "The attack just unsignificantly bounced on FR4G-TP <" << (*this)._name << ">'s armor causing no effects" << std::endl;
	}
	else
	{
		if ((*this)._hit_points < resulting_damage)
		{
			(*this)._hit_points = 0;
			std::cout << "The attack slayed FR4G-TP <" << (*this)._name << ">" << std::endl;
		}
		else
		{
			(*this)._hit_points = (*this)._hit_points - resulting_damage;
			std::cout << "FR4G-TP <" << (*this)._name << "> has taken " << resulting_damage << "points of damage !" << std::endl;
		}
	}
}

void			FragTrap::beRepaired(unsigned int const amount)
{
	unsigned int	resulting_heal;

	if ((*this)._hit_points == (*this)._max_hit_points)
	{
		std::cout << "FR4G-TP <" << (*this)._name << "> can't be repaired since it's full life already !" << std::endl;
	}
	else
	{
		resulting_heal = ((*this)._hit_points + amount > (*this)._max_hit_points) ? (*this)._max_hit_points - (*this)._hit_points : amount;
		(*this)._hit_points = (*this)._hit_points + resulting_heal;
		std::cout << "FR4G-TP <" << (*this)._name << "> got healed " << resulting_heal << " hp" << std::endl;
	}
}

void		FragTrap::vault_hunter_dot_exe(std::string const &target)
{
	(void)target;
	std::cout << "RandomAttack!" << std::endl;
	(*this)._energy_points = ((*this)._energy_points < 25) ? 0 : (*this)._energy_points - 25;
}

/**
 * Private method(s)
 */

/**
 * '<<' operator surcharge
 */

std::ostream	&operator<<(std::ostream &o, FragTrap const &rhs)
{
	std::cout << "| Name: " << rhs.getName() << std::endl;
	std::cout << "| Level: " << rhs.getLevel() << std::endl;
	std::cout << "| Hit Points: " << rhs.getHitPoints() << std::endl;
	std::cout << "| Energy Points: " << rhs.getEnergyPoints() << std::endl;
	return (o);
}
