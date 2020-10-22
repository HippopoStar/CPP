#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <sstream>
# include <iomanip>
# include <iostream>
# include <string>

class	Brain
{
	public:
		Brain(void);
		~Brain(void);

		std::string	identify(void) const;

	private:
		std::string const	_cortex_content;
		std::string const	_lymbic_system_content;

};

#endif
