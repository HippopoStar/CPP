#include "ZombieEvent.hpp"

/**
 * Constructor(s) & Destructor(s)
 */

ZombieEvent::ZombieEvent(void) : _zombie_type("generic")
{
}

ZombieEvent::~ZombieEvent(void)
{
}

/**
 * Public method(s)
 */

void	ZombieEvent::setZombieType(std::string const &zombie_type)
{
	(*this)._zombie_type = zombie_type;
}

Zombie	*ZombieEvent::newZombie(void) const
{
	return (new Zombie((*this)._zombie_type));
}

Zombie	*ZombieEvent::newZombie(std::string const &name) const
{
	return (new Zombie((*this)._zombie_type, name));
}

Zombie	*ZombieEvent::randomChump(void) const
{
	Zombie			*random_chump;

	random_chump = (*this).newZombie();
	(*random_chump).announce();
	return (random_chump);
}
