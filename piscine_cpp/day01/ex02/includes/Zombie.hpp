#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	public:
		Zombie(void);
		Zombie(std::string const &name, std::string const &type);
		~Zombie(void);

		void	advert(void) const;
		void	announce(void) const;

	private:
		std::string	_name;
		std::string	_type;

};

#endif
