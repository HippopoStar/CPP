#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateria.hpp"
# include "AMateria.hpp"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		virtual ~MateriaSource(void);

		AMateria			*[4]getList(void) const;
		virtual void		learnMateria(AMateria *m);
		virtual AMateria	*createMateria(std::string const &type);

	private:
		AMateria			*_list[4];

};

std::ostream	&operator<<(std::ostream &o, MateriaSource const &rhs);

#endif
