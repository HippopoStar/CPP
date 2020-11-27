#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Cure : public AMateria
{
	public:
		Cure(void);
		virtual ~Cure(void);

		virtual Amateria	*clone(void) const;
		virtual void		use(ICharacter &target);

};

std::ostream	&operator<<(std::ostream &o, Cure const &rhs);

#endif
