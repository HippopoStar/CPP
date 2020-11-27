#include "MateriaSource.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

MateriaSource::MateriaSource(void) : _list({ NULL, NULL, NULL, NULL })
{
	std::cout << "<MateriaSource> Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	std::cout << "<MateriaSource> Copy constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "<MateriaSource> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	std::cout << "<Character> Assignement operator called" << std::endl;
	(*this)._inventory[0] = rhs.getList()[0];
	(*this)._inventory[1] = rhs.getList()[1];
	(*this)._inventory[2] = rhs.getList()[2];
	(*this)._inventory[3] = rhs.getList()[3];
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, MateriaSource const &rhs)
{
	o << "<MateriaSource> operator \"<<\" called" << std::endl;
	o << "| List:" << std::endl;
	o << "|\t" << rhs.getList()[0].getType() << std::endl;
	o << "|\t" << rhs.getList()[1].getType() << std::endl;
	o << "|\t" << rhs.getList()[2].getType() << std::endl;
	o << "|\t" << rhs.getList()[3].getType() << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

AMateria		*[4]getList(void) const
{
	return ((*this)._list);
}

void			learnMateria(AMateria *m)
{
	int		i;

	i = 0;
	while (i < 4 && !((*this)._list[i] == NULL))
	{
		i++;
	}
	if (i < 4)
	{
		(*this)._list[i] = m;
	}
}

AMateria		*createMateria(std::string const &type)
{
	int		i;

	i = 0;
	while (i < 4 && !(type == (*this)._list[i].getType()))
	{
		i++;
	}
	return (i < 4 ? (*this)._list[i] : NULL);
}

/**
 * Private method(s)
 */

