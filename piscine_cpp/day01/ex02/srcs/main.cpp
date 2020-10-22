#include <cstdlib>
#include <ctime>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main(void)
{
	Zombie		stack_zombie("ZombieStack", "creeper");
	Zombie		*heap_zombie;
	ZombieEvent	z_event;

	srand(time(NULL));
	z_event.setZombieType("imp");
	heap_zombie = z_event.newZombie("ZombieHeap");
	(*heap_zombie).advert();
	delete heap_zombie;
	heap_zombie = z_event.randomChump();
	delete heap_zombie;
	stack_zombie.advert();
	return (0);
}
