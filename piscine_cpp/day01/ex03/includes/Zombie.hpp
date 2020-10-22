#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <cstdlib>
# include <iostream>
# include <string>

class	Zombie
{
	public:
		Zombie(void);
		Zombie(std::string const &type);
		Zombie(std::string const &type, std::string const &name);
		~Zombie(void);

		void	advert(void) const;
		void	announce(void) const;

	private:
		std::string const	_type;
		std::string const	_name;

		static std::string const	_first_syllabs[30];
		static std::string const	_last_syllabs[29];

		void		_constructor_didascalie(void) const;
		std::string	_generate_random_name(void) const;
};

#endif
