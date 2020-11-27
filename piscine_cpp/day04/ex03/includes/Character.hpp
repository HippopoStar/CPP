#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character : public ICharacter
{
	public:
		Character(std::string const &name);
		virtual ~Character(void);

		virtual std::string const	&getName(void) const;
		AMateria					*[4]getInventory(void) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);

	private:
		Character(void);

		std::string const	_name;
		AMateria			*_inventory[4];

};

std::ostream	&operator<<(std::ostream &o, Character const &rhs);

#endif
