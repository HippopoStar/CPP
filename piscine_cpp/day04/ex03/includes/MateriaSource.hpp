#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &rhs);
		virtual ~MateriaSource(void);

		MateriaSource		&operator=(MateriaSource const &rhs);
		AMateria			**getList(void) const;
		virtual void		learnMateria(AMateria *m);
		virtual AMateria	*createMateria(std::string const &type);

	private:
		AMateria			*_list[4];

};

std::ostream	&operator<<(std::ostream &o, MateriaSource const &rhs);

#endif
