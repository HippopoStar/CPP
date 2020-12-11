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
		Ice(Ice const &src);
		virtual ~Ice(void);

		Ice		&operator=(Ice const &rhs);
		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter &target);

};

std::ostream	&operator<<(std::ostream &o, Ice const &rhs);

#endif
