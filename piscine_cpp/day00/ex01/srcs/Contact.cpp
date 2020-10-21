#include "Contact.hpp"
#include <functional>

static bool		check_empty_string(const std::string &s)
{
	return (s.length() == 0 ? false : true);
}

/*
 * Constructor(s) & Destructor(s)
 */

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

/**
 * Private method(s)
 */

void		Contact::_error_empty_field(void) const
{
	std::cout << "-field can not be empty-" << std::endl;
}

/*
**bool		Contact::_check_empty_string(const std::string &s) const
**{
**	return (s.length() == 0 ? false : true);
**}
*/

std::string	Contact::_query_field(const char *field, bool (*f)(const std::string&))
{
	std::string	input;

	do
	{
		std::cout << field << ": ";
		std::getline(std::cin, input);
	}
	while (!(f == NULL) && f(input) == false);
	return (input);
}

/**
 * Public method(s)
 */

void		Contact::create_contact(void)
{
	(*this).set_first_name((*this)._query_field("First name", check_empty_string));
	(*this).set_last_name((*this)._query_field("Last name", check_empty_string));
	(*this).set_nickname((*this)._query_field("Nickname", check_empty_string));
	(*this).set_login((*this)._query_field("Login", check_empty_string));
	(*this).set_postal_address((*this)._query_field("Postal address", check_empty_string));
	(*this).set_email_address((*this)._query_field("Email address", check_empty_string));
	(*this).set_phone_number((*this)._query_field("Phone number", check_empty_string));
	(*this).set_birthday_date((*this)._query_field("Birthday date", check_empty_string));
	(*this).set_favourite_meal((*this)._query_field("Favourite meal", check_empty_string));
	(*this).set_underwear_color((*this)._query_field("Underwear color", check_empty_string));
	(*this).set_darkest_secret((*this)._query_field("Darkest color", check_empty_string));
/*
**	(*this).set_first_name((*this)._query_field("First name", (*this)._check_empty_string));
**	(*this).set_last_name((*this)._query_field("Last name", (*this)._check_empty_string));
**	(*this).set_nickname((*this)._query_field("Nickname", (*this)._check_empty_string));
**	(*this).set_login((*this)._query_field("Login", (*this)._check_empty_string));
**	(*this).set_postal_address((*this)._query_field("Postal address", (*this)._check_empty_string));
**	(*this).set_email_address((*this)._query_field("Email address", (*this)._check_empty_string));
**	(*this).set_phone_number((*this)._query_field("Phone number", (*this)._check_empty_string));
**	(*this).set_birthday_date((*this)._query_field("Birthday date", (*this)._check_empty_string));
**	(*this).set_favourite_meal((*this)._query_field("Favourite meal", (*this)._check_empty_string));
**	(*this).set_underwear_color((*this)._query_field("Underwear color", (*this)._check_empty_string));
**	(*this).set_darkest_secret((*this)._query_field("Darkest color", (*this)._check_empty_string));
*/
}

/**
 * SET
 */

bool		Contact::set_first_name(const std::string &first_name)
{
	if (first_name.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._first_name = first_name;
	return (true);
}

bool		Contact::set_last_name(const std::string &last_name)
{
	if (last_name.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._last_name = last_name;
	return (true);
}

bool		Contact::set_nickname(const std::string &nickname)
{
	if (nickname.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._nickname = nickname;
	return (true);
}

bool		Contact::set_login(const std::string &login)
{
	if (login.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._login = login;
	return (true);
}

bool		Contact::set_postal_address(const std::string &postal_address)
{
	if (postal_address.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._postal_address = postal_address;
	return (true);
}

bool		Contact::set_email_address(const std::string &email_address)
{
	if (email_address.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._email_address = email_address;
	return (true);
}

bool		Contact::set_phone_number(const std::string &phone_number)
{
	if (phone_number.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._phone_number = phone_number;
	return (true);
}

bool		Contact::set_birthday_date(const std::string &birthday_date)
{
	if (birthday_date.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._birthday_date = birthday_date;
	return (true);
}

bool		Contact::set_favourite_meal(const std::string &favourite_meal)
{
	if (favourite_meal.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._favourite_meal = favourite_meal;
	return (true);
}

bool		Contact::set_underwear_color(const std::string &underwear_color)
{
	if (underwear_color.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._underwear_color = underwear_color;
	return (true);
}

bool		Contact::set_darkest_secret(const std::string &darkest_secret)
{
	if (darkest_secret.length() == 0)
	{
		(*this)._error_empty_field();
		return (false);
	}
	(*this)._darkest_secret = darkest_secret;
	return (true);
}

/**
 * GET
 */

std::string	Contact::get_first_name(void) const
{
	return ((*this)._first_name);
}

std::string	Contact::get_last_name(void) const
{
	return ((*this)._last_name);
}

std::string	Contact::get_nickname(void) const
{
	return ((*this)._nickname);
}

std::string	Contact::get_login(void) const
{
	return ((*this)._login);
}

std::string	Contact::get_postal_address(void) const
{
	return ((*this)._postal_address);
}

std::string	Contact::get_email_address(void) const
{
	return ((*this)._email_address);
}

std::string	Contact::get_phone_number(void) const
{
	return ((*this)._phone_number);
}

std::string	Contact::get_birthday_date(void) const
{
	return ((*this)._birthday_date);
}

std::string	Contact::get_favourite_meal(void) const
{
	return ((*this)._favourite_meal);
}

std::string	Contact::get_underwear_color(void) const
{
	return ((*this)._underwear_color);
}

std::string	Contact::get_darkest_secret(void) const
{
	return ((*this)._darkest_secret);
}
