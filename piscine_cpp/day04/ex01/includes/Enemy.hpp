#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include <string>

class	Enemy
{
	public:
		Enemy(int hp, std::string const &type);
		Enemy(Enemy const &src);
		virtual ~Enemy(void);

		Enemy				&operator=(Enemy const &rhs);
		std::string const	&getType(void) const;
		int					getHP(void) const;

		virtual void		takeDamage(int);

	private:
		Enemy(void);

	protected:
		int				_hp;
		std::string		_type;

};

std::ostream	&operator<<(std::ostream &o, Enemy const &rhs);

#endif
