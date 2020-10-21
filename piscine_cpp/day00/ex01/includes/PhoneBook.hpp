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

	Contact		_contact_list[8];

	void		_summary(void) const;
	size_t		_query_index(void) const;
};

#endif
