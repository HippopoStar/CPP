#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
	public:

		Contact(void);
		~Contact(void);

		void	create_contact(void);
		bool	is_empty(void) const;
		void	display(void) const;

		bool	set_first_name(const std::string &first_name);
		bool	set_last_name(const std::string &last_name);
		bool	set_nickname(const std::string &nickname);
		void	set_login(const std::string &login);
		void	set_postal_address(const std::string &postal_address);
		void	set_email_address(const std::string &email_address);
		void	set_phone_number(const std::string &phone_number);
		void	set_birthday_date(const std::string &birthday_date);
		void	set_favourite_meal(const std::string &favourite_meal);
		void	set_underwear_color(const std::string &underwear_color);
		void	set_darkest_secret(const std::string &darkest_secret);

		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_login(void) const;
		std::string	get_postal_address(void) const;
		std::string	get_email_address(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_birthday_date(void) const;
		std::string	get_favourite_meal(void) const;
		std::string	get_underwear_color(void) const;
		std::string	get_darkest_secret(void) const;

	private:

		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_login;
		std::string	_postal_address;
		std::string	_email_address;
		std::string	_phone_number;
		std::string	_birthday_date;
		std::string	_favourite_meal;
		std::string	_underwear_color;
		std::string	_darkest_secret;


		bool		_check_empty_string(const std::string &s) const;
		std::string	_query_field(const char *field, bool (Contact::*f)(const std::string &) const);

};

#endif
