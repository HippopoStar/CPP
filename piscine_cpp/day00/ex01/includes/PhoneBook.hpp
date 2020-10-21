#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	public:

	PhoneBook(void);
	~PhoneBook(void);

	void	search(void) const;
	void	add(void);

	private:

	Contact		contact_list[8];
};

#endif
