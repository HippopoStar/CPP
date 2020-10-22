#include "Contact.hpp"

/*
 * Constructor(s) & Destructor(s)
 */

Contact::Contact(void) : _first_name(""), _last_name(""), _nickname("")
{
}

Contact::~Contact(void)
{
}

/**
 * Private method(s)
 */

bool		Contact::_check_empty_string(const std::string &s) const
{
	if (s.length() == 0)
	{
		std::cout << "-field can not be empty-" << std::endl;
		return (false);
	}
	return (true);
}

std::string	Contact::_query_field(const char *field, bool (Contact::*f)(const std::string &) const)
{
	std::string	input;

	do
	{
		std::cout << field << ": ";
		std::getline(std::cin, input);
	}
	while (!(f == NULL) && ((*this).*f)(input) == false);
	return (input);
}

/**
 * Public method(s)
 */

void		Contact::create_contact(void)
{
	(*this).set_first_name((*this)._query_field("First name", &Contact::_check_empty_string));
	(*this).set_last_name((*this)._query_field("Last name", &Contact::_check_empty_string));
	(*this).set_nickname((*this)._query_field("Nickname", &Contact::_check_empty_string));
	(*this).set_login((*this)._query_field("Login", NULL));
	(*this).set_postal_address((*this)._query_field("Postal address", NULL));
	(*this).set_email_address((*this)._query_field("Email address", NULL));
	(*this).set_phone_number((*this)._query_field("Phone number", NULL));
	(*this).set_birthday_date((*this)._query_field("Birthday date", NULL));
	(*this).set_favourite_meal((*this)._query_field("Favourite meal", NULL));
	(*this).set_underwear_color((*this)._query_field("Underwear color", NULL));
	(*this).set_darkest_secret((*this)._query_field("Darkest color", NULL));
}

bool		Contact::is_empty(void) const
{
	return ((*this)._first_name.length() > 0
			&& (*this)._last_name.length() > 0
			&& (*this)._nickname.length() > 0 ? false : true);
}

void		Contact::display(void) const
{
	std::cout << "First name: " << (*this)._first_name << std::endl;
	std::cout << "Last name: " << (*this)._last_name << std::endl;
	std::cout << "Nickname: " << (*this)._nickname << std::endl;
	std::cout << "Login: " << (*this)._login << std::endl;
	std::cout << "Postal address: " << (*this)._postal_address << std::endl;
	std::cout << "Email address: " << (*this)._email_address << std::endl;
	std::cout << "Phone number: " << (*this)._phone_number << std::endl;
	std::cout << "Birthday date: " << (*this)._birthday_date << std::endl;
	std::cout << "Favourite meal: " << (*this)._favourite_meal << std::endl;
	std::cout << "Underwear color: " << (*this)._underwear_color << std::endl;
	std::cout << "Darkest secret: " << (*this)._darkest_secret << std::endl;
}

/**
 * SET
 */

bool		Contact::set_first_name(const std::string &first_name)
{
	if (first_name.length() == 0)
	{
		return (false);
	}
	(*this)._first_name = first_name;
	return (true);
}

bool		Contact::set_last_name(const std::string &last_name)
{
	if (last_name.length() == 0)
	{
		return (false);
	}
	(*this)._last_name = last_name;
	return (true);
}

bool		Contact::set_nickname(const std::string &nickname)
{
	if (nickname.length() == 0)
	{
		return (false);
	}
	(*this)._nickname = nickname;
	return (true);
}

void		Contact::set_login(const std::string &login)
{
	(*this)._login = login;
}

void		Contact::set_postal_address(const std::string &postal_address)
{
	(*this)._postal_address = postal_address;
}

void		Contact::set_email_address(const std::string &email_address)
{
	(*this)._email_address = email_address;
}

void		Contact::set_phone_number(const std::string &phone_number)
{
	(*this)._phone_number = phone_number;
}

void		Contact::set_birthday_date(const std::string &birthday_date)
{
	(*this)._birthday_date = birthday_date;
}

void		Contact::set_favourite_meal(const std::string &favourite_meal)
{
	(*this)._favourite_meal = favourite_meal;
}

void		Contact::set_underwear_color(const std::string &underwear_color)
{
	(*this)._underwear_color = underwear_color;
}

void		Contact::set_darkest_secret(const std::string &darkest_secret)
{
	(*this)._darkest_secret = darkest_secret;
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
