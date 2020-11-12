#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class	Peon : public Victim
{
	public:
		Peon(std::string const &name);
		Peon(Peon const &src);
		~Peon(void);

		Peon			&operator=(Peon const &rhs);

		virtual void		getPolymorphed(void) const;

	private:
		Peon(void);

};

/*
**std::ostream	&operator<<(std::ostream &o, Peon const &rhs);
*/

#endif
