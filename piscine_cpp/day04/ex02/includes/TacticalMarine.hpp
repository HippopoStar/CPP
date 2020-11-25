#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include <iostream>
# include <string>
# include <ISpaceMarine.hpp>

class	TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine(void);
		TacticalMarine(TacticalMarine const &src);
		virtual	~TacticalMarine(void);

		TacticalMarine		&operator=(TacticalMarine const &rhs);
		virtual ISpaceMarine	*clone(void) const;
		virtual void			battleCry(void) const;
		virtual void			rangedAttack(void) const;
		virtual void			meleeAttack(void) const;

};


std::ostream	&operator<<(std::ostream &o, TacticalMarine const &rhs);


#endif
