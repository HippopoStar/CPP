#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>

class	FragTrap
{
	public:
		FragTrap(void);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &rhs);
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getLevel(void) const;
		std::string	getName(void) const;
		unsigned int	getMeleeAttackDamage(void) const;
		unsigned int	getRangedAttackDamage(void) const;
		unsigned int	getArmorDamageReduction(void) const;
		void		rangedAttack(std::string const &target) const;
		void		meleeAttack(std::string const &target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		unsigned int		_hit_points;
		unsigned int const	_max_hit_points;
		unsigned int		_energy_points;
		unsigned int const	_max_energy_points;
		unsigned int		_level;
		std::string		_name;
		unsigned int		_melee_attack_damage;
		unsigned int		_ranged_attack_damage;
		unsigned int		_armor_damage_reduction;

};

#endif
