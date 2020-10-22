#include <cstdlib>
#include <ctime>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int		main(void)
{
	ZombieHorde	alliance(10);

	srand(time(NULL));
	alliance.announce();
	return (0);
}
