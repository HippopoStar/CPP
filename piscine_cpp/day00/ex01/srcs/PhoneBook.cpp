#include "PhoneBook.hpp"

/**
 * Constructor(s) & Destructor(s)
 */

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

/**
 * Private method(s)
 */

void	PhoneBook::_summary(void) const
{
	size_t		index;

	index = 0;
	while (index < 8)
	{
		if (!(*this)._contact_list[index].is_empty())
		{
			std::cout << (index + 1);
			(*this)._contact_list[index].display(); //TODO
		}
		index++;
	}
}

size_t	PhoneBook::_query_index(void) const
{
	size_t		index;
	std::string	s;

	do
	{
		std::cout << "Chose a contact to display [1-8]: ";
		std::getline(std::cin, s);
	}
	while (!((s.length() == 1) && ('0' <= s.at(0) && s.at(0) <= '9')
			&& (0 < (index = (size_t)std::stoul(s, NULL, 10)) && index < 9)));
	return (index - 1);
}

/**
 * Public method(s)
 */

void	PhoneBook::search(void) const
{
	size_t		index;

	(*this)._summary();
	index = (*this)._query_index();
	if (!(*this)._contact_list[index].is_empty())
	{
		(*this)._contact_list[index].display();
	}
	else
	{
		std::cout << "No contact registered at this index" << std::endl;
	}
}

void	PhoneBook::add(void)
{
	(*this)._contact_list[7] = (*this)._contact_list[6];
	(*this)._contact_list[6] = (*this)._contact_list[5];
	(*this)._contact_list[5] = (*this)._contact_list[4];
	(*this)._contact_list[4] = (*this)._contact_list[3];
	(*this)._contact_list[3] = (*this)._contact_list[2];
	(*this)._contact_list[2] = (*this)._contact_list[1];
	(*this)._contact_list[1] = (*this)._contact_list[0];
	(*this)._contact_list[0].create_contact();
}
