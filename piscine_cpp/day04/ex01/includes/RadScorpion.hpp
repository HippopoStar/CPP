#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include <iostream>
# include <string>
# include "Enemy.hpp"

class	RadScorpion : public Enemy
{
	public:
		RadScorpion(void);
		RadScorpion const &src);
		virtual ~RadScorpion(void);

		RadScorpion		&operator=(RadScorpion const &rhs);

		virtual void		takeDamage(void);

};

/*
**std::ostream	&operator<<(std::ostream &o, RadScorpion const &rhs);
*/

#endif
