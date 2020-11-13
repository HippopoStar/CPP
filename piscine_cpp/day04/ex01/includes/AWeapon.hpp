#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class	AWeapon
{
	public:
		AWeapon(std::string const &name, int apcost, int damage);
		AWeapon(AWeapon const &src);
		virtual ~AWeapon(void);

		AWeapon		&operator=(AWeapon const &rhs);
		std::string const	&getName(void) const;
		int					getAPCost(void) const;
		int					getDamage(void) const;

		virtual void		attack(void) const = 0;

	private:
		AWeapon(void);

	protected:
		std::string		_name;
		int				_apcost;
		int				_damage;

};

std::ostream	&operator<<(std::ostream &o, AWeapon const &rhs);

#endif
