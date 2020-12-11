#include "AMateria.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

AMateria::AMateria(void) : _type("default"), _xp(0)
{
	std::cout << "<AMateria> Default constructor called" << std::endl;
}

AMateria::AMateria(std::string  const &type) : _type(type), _xp(0)
{
	std::cout << "<AMateria> Constructor called with parameter [\"" << type << "\"]" << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
	std::cout << "<AMateria> Copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria(void)
{
	std::cout << "<AMateria> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

AMateria		&AMateria::operator=(AMateria const &rhs)
{
	std::cout << "<AMateria> Assignement operator called" << std::endl;
	(*this)._type = rhs.getType();
	(*this)._xp = rhs.getXP();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, AMateria const &rhs)
{
	o << "<AMateria> operator \"<<\" called" << std::endl;
	o << "| Type: " << rhs.getType() << std::endl;
	o << "| XP: " << rhs.getXP() << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&AMateria::getType(void) const
{
	return ((*this)._type);
}

unsigned int		AMateria::getXP(void) const
{
	return ((*this)._xp);
}

void				AMateria::use(ICharacter &target)
{
	std::cout << "<AMateria> " << (*this)._type << " used!" << std::endl;
	(*this)._xp = (*this)._xp + 10;
	(void)target;
}

/**
 * Private method(s)
 */

