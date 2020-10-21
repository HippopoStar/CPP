#include "PhoneBook.hpp"

int		main(void)
{
	std::string	s;
	PhoneBook	annuaire;

	do
	{
		std::getline(std::cin, s);
		if (s == "ADD")
		{
			annuaire.add();
		}
		else if (s == "SEARCH")
		{
			annuaire.search();
		}
	}
	while (!(s == "EXIT"));
	return (0);
}
