#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class	Human
{
	public:
		Human(void);
		~Human(void);

		std::string	identify(void) const;
		Brain const	&getBrain(void) const;

	private:
		Brain const	_nut;

		Brain		_gather_brain(void);
};

#endif
