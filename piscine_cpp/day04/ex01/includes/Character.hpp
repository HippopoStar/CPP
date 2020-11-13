#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class	Character
{
	public:
		Character(std::string const &name);
		Character(Character const &src);
		~Character(void);

		Character			&operator=(Character const &rhs);
		std::string const	&getName(void) const;
		int			getAP(void) const;
		AWeapon			*getWeapon(void) const;

		void				recoverAP(void);
		void				equip(AWeapon *weapon);
		void				attack(Enemy *enemy);

	private:
		Character(void);

		std::string		_name;
		int				_ap;
		AWeapon			*_weapon;

};

std::ostream	&operator<<(std::ostream &o, Character const &rhs);

#endif
