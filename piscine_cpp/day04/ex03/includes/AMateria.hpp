#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class	AMateria
{
	public:
		AMateria(std::string const &type);
		Amateria(Amateria const &src);
		virtual ~AMateria(void);

		std::string const	&getType(void) const; //Returns the materia type
		unsigned int		getXP(void) const; //Returns the Materia's XP

		virtual Amateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

	private:
		std::string			_type;
		unsigned int		_xp;

};

std::ostream	&operator<<(std::ostream &o, Amateria const &rhs);

#endif
