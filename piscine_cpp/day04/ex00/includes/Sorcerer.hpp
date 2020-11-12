#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class	Sorcerer
{
	public:
		Sorcerer(std::string const &name, std::string const &title);
		Sorcerer(Sorcerer const &src);
		~Sorcerer(void);

		Sorcerer		&operator=(Sorcerer const &rhs);
		std::string const	&getName(void) const;
		std::string const	&getTitle(void) const;

		void		polymorph(Victim const &victim) const;

	private:
		Sorcerer(void);

		std::string		_name;
		std::string		_title;

};

std::ostream	&operator<<(std::ostream &o, Sorcerer const &rhs);

#endif
