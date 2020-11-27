#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Ice : public AMateria
{
	public:
		Ice(void);
		virtual ~Ice(void);

		virtual Amateria	*clone(void) const;
		virtual void		use(ICharacter &target);

};

std::ostream	&operator<<(std::ostream &o, Ice const &rhs);

#endif
