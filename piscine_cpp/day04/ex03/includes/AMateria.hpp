#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class	ICharacter;

class	AMateria
{
	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		virtual ~AMateria(void);

		AMateria	&operator=(AMateria const &rhs);
		std::string const	&getType(void) const; //Returns the Materia type
		unsigned int		getXP(void) const; //Returns the Materia's XP

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

	private:
		AMateria(void);

		std::string			_type;
		unsigned int		_xp;

};

std::ostream	&operator<<(std::ostream &o, AMateria const &rhs);

#endif
