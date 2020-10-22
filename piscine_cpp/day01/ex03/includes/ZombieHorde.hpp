#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <iostream>
# include <string>
# include "Zombie.hpp"

class	ZombieHorde
{
	public:
		ZombieHorde(int const n);
		~ZombieHorde(void);

		void	announce(void) const;

	private:
		Zombie const	*_zombie_horde;
		size_t const	_zombie_horde_size;
};

#endif
