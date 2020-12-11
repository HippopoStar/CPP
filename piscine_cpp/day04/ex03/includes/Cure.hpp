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
		Cure(Cure const &src);
		virtual ~Cure(void);

		Cure		&operator=(Cure const &rhs);
		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter &target);

};

std::ostream	&operator<<(std::ostream &o, Cure const &rhs);

#endif
