#include "Squad.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

Squad::Squad(void) : _members(NULL)
{
	std::cout << "<Squad> Default constructor called" << std::endl;
}

Squad::Squad(Squad const &src)
{
	std::cout << "<Squad> Copy constructor called" << std::endl;
	*this = src;
}

Squad::~Squad(void)
{
	std::cout << "<Squad> Destructor called" << std::endl;
	(*this)._purge_members();
}

/**
 * Operator overload(s)
 */

Squad		&Squad::operator=(Squad const &rhs)
{
	std::cout << "<Squad> Assignement operator called" << std::endl;
	(*this)._copy_members(rhs);
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Squad const &rhs)
{
	t_squad_member	*tmp;

	tmp = rhs.getMembers();
	while (!(tmp == NULL))
	{
		o << tmp;
		tmp = tmp->next;
	}
	return (o);
}

/**
 * Public method(s)
 */

int						Squad::getCount(void) const
{
	int				i;
	t_squad_member	*tmp;

	i = 0;
	tmp = (*this)._members;
	while (!(tmp == NULL))
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

ISpaceMarine			*Squad::getUnit(int n) const
{
	int				i;
	t_squad_member	*tmp;

	i = 0;
	tmp = (*this)._members;
	while (!(i == n || tmp == NULL))
	{
		i++;
		tmp = tmp->next;
	}
	return (tmp->unit);
}

int					Squad::push(ISpaceMarine *xxx)
{
	t_squad_member	**tmp;

	if (!(xxx == NULL))
	{
		tmp = &((*this)._members);
		while (!((*tmp) == NULL))
		{
			tmp = &((*tmp)->next);
		}
		(*tmp) = new t_squad_member;
		(*tmp)->unit = xxx;
		(*tmp)->next = NULL;
		return (1);
	}
	return (0);
}

t_squad_member			*Squad::getMembers(void) const
{
	return ((*this)._members);
}

/**
 * Private method(s)
 */

void			Squad::_purge_members(void)
{
	t_squad_member	*tmp;

	while (!((tmp = (*this)._members) == NULL))
	{
		(*this)._members = ((*this)._members)->next;
		delete tmp->unit;
		delete tmp;
	}
}

void			Squad::_copy_members(Squad const &rhs)
{
	t_squad_member	*tmp;

	(*this)._purge_members();
	tmp = rhs.getMembers();
	while (!(tmp == NULL))
	{
		(*this).push((*(tmp->unit)).clone());
		tmp = tmp->next;
	}
}

