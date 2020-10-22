#include "ZombieEvent.hpp"

/**
 * Non-member attribute(s) initialization
 */

std::string const	ZombieEvent::_first_syllabs[30] =
	{
		"Grak'", "Huk", "Kal'", "Mak", "Jhom",
		"Juk'", "Than", "Zag'", "Zang", "Zhar'",
		"Bar", "Grim", "Hath", "Hel", "Sar",
		"Thok", "Char", "Klath", "Mezz", "Tang",
		"Thog", "Bel", "Graz'", "Krak", "Orm",
		"Krag", "Phan", "Thul", "Jhaz", "Kon"
	};
std::string const	ZombieEvent::_last_syllabs[29] =
	{
		"gore", "crast", "mon", "nar", "dok",
		"nagma", "thang", "moth", "nak", "tast",
		"taz", "thyk", "vugh", "zazt", "gak",
		"gorg", "grave", "juk", "kath", "kresh",
		"los", "phog", "nos", "rath", "garth",
		"gron", "krit", "nuz", "thak"
	};

/**
 * Constructor(s) & Destructor(s)
 */

ZombieEvent::ZombieEvent(void)
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

Zombie	*ZombieEvent::newZombie(std::string const &name) const
{
	return (new Zombie(name, (*this)._zombie_type));
}

Zombie	*ZombieEvent::randomChump(void) const
{
	std::string		random_name;
	Zombie			*random_chump;

	random_name = (*this)._first_syllabs[rand() % 30] + (*this)._last_syllabs[rand() % 29];
	random_chump = (*this).newZombie(random_name);
	//(*random_chump).announce();
	(*random_chump).advert();
	return (random_chump);
}
