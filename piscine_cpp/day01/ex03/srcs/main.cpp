#include <cstdlib>
#include <ctime>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int		main(void)
{
	srand(time(NULL));
	ZombieHorde	alliance(10);

	alliance.announce();
	return (0);
}
