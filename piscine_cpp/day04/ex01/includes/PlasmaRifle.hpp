#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"

class	PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle const &src);
		virtual ~PlasmaRifle(void);

		PlasmaRifle			&operator=(PlasmaRifle const &rhs);

		virtual void		attack(void) const;

};

/*
**std::ostream	&operator<<(std::ostream &o, PlasmaRifle const &rhs);
*/

#endif
