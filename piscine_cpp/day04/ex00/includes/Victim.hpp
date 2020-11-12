#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class	Victim
{
	public:
		Victim(std::string const &name);
		Victim(Victim const &src);
		~Victim(void);

		Victim			&operator=(Victim const &rhs);
		std::string const	&getName(void) const;

		virtual void		getPolymorphed(void) const;

	private:
		Victim(void);

	protected:
		std::string		_name;

};

std::ostream	&operator<<(std::ostream &o, Victim const &rhs);

#endif
