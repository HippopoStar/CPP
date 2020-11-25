#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <iostream>
# include <string>
# include <ISquad.hpp>

typedef struct	s_squad_member
{
	ISpaceMarine			*unit;
	struct s_squad_member	*next;
}				t_squad_member;

class	Squad : public ISquad
{
	public:
		Squad(void);
		Squad(Squad const &src);
		virtual	~Squad(void);

		Squad				&operator=(Squad const &rhs);
		virtual int				getCount(void) const;
		virtual ISpaceMarine	*getUnit(int n) const;
		virtual int				push(ISpaceMarine *xxx);

		t_squad_member		*getMembers(void) const;

	private:

		t_squad_member	*_members;

		void					_purge_members(void);
		void					_copy_members(Squad const &rhs);

};

std::ostream	&operator<<(std::ostream &o, Squad const &rhs);

#endif
