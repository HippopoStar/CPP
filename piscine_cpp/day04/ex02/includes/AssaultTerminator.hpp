#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <iostream>
# include <string>
# include <ISpaceMarine.hpp>

class	AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator(void);
		AssaultTerminator(AssaultTerminator const &src);
		virtual	~AssaultTerminator(void);

		AssaultTerminator	&operator=(AssaultTerminator const &rhs);
		virtual ISpaceMarine	*clone(void) const;
		virtual void			battleCry(void) const;
		virtual void			rangedAttack(void) const;
		virtual void			meleeAttack(void) const;

};


std::ostream	&operator<<(std::ostream &o, AssaultTerminator const &rhs);


#endif
