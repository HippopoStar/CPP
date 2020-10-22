#include "ZombieHorde.hpp"

/**
 * Constructor(s) & Destructor(s)
 */

ZombieHorde::ZombieHorde(int const n) : _zombie_horde(new Zombie[n > 0 ? n : 1]), _zombie_horde_size(n)
{
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] (*this)._zombie_horde;
}

/**
 * Public method(s)
 */

void	ZombieHorde::announce(void) const
{
	size_t	i;

	i = 0;
	while (i < (*this)._zombie_horde_size)
	{
		(*this)._zombie_horde[i].announce();
		i++;
	}
}
