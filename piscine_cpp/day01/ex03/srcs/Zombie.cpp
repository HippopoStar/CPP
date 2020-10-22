#include "Zombie.hpp"

/**
 * Non-member attribute(s) initialization
 */

std::string const	Zombie::_first_syllabs[30] =
	{
		"Grak'", "Huk", "Kal'", "Mak", "Jhom",
		"Juk'", "Than", "Zag'", "Zang", "Zhar'",
		"Bar", "Grim", "Hath", "Hel", "Sar",
		"Thok", "Char", "Klath", "Mezz", "Tang",
		"Thog", "Bel", "Graz'", "Krak", "Orm",
		"Krag", "Phan", "Thul", "Jhaz", "Kon"
	};
std::string const	Zombie::_last_syllabs[29] =
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

Zombie::Zombie(void) : _type("generic"), _name((*this)._generate_random_name())
{
	(*this)._constructor_didascalie();
}

Zombie::Zombie(std::string const &type) : _type(type), _name((*this)._generate_random_name())
{
	(*this)._constructor_didascalie();
}

Zombie::Zombie(std::string const &type, std::string const &name) : _type(type), _name(name)
{
	(*this)._constructor_didascalie();
}

Zombie::~Zombie(void)
{
	std::cout << "* Zombie " << (*this)._name << " (" << (*this)._type << ") passed away anew. *" << std::endl;
}

/**
 * Public method(s)
 */

void	Zombie::advert(void) const
{
	std::cout << "<" << (*this)._name << " (" << (*this)._type << ")> Braiiiiiiinnnssss ..." << std::endl;
}

void	Zombie::announce(void) const
{
	(*this).advert();
}

/**
 * Private method(s)
 */

void		Zombie::_constructor_didascalie(void) const
{
	std::cout << "* Zombie " << (*this)._name << " (" << (*this)._type << ") just rose from the underneath world ! *" << std::endl;
}

std::string	Zombie::_generate_random_name(void) const
{
	std::string	random_name;

	random_name = (*this)._first_syllabs[rand() % 30] + (*this)._last_syllabs[rand() % 29];
	return (random_name);
}
