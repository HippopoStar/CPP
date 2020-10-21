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

/**
 * Public method(s)
 */

void	PhoneBook::search(void) const
{
}

void	PhoneBook::add(void)
{
	(*this).contact_list[7] = (*this).contact_list[6];
	(*this).contact_list[6] = (*this).contact_list[5];
	(*this).contact_list[5] = (*this).contact_list[4];
	(*this).contact_list[4] = (*this).contact_list[3];
	(*this).contact_list[3] = (*this).contact_list[2];
	(*this).contact_list[2] = (*this).contact_list[1];
	(*this).contact_list[1] = (*this).contact_list[0];
	(*this).contact_list[0].create_contact();
}
