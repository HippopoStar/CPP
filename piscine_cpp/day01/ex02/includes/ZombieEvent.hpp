#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "Zombie.hpp"

class	ZombieEvent
{
	public:
		ZombieEvent(void);
		~ZombieEvent(void);

		void	setZombieType(std::string const &zombie_type);
		Zombie	*newZombie(std::string const &name) const;
		/**
		 * Reflexion concernant le type de retour de la fonction "randomChump" :
		 * La fonction cree un Zombie sur le tas et renvoie un pointeur vers celui-ci,
		 * car dans le cas ou elle creerait un Zombie sur la pile et le renverrait,
		 * cela impliquerait que dans la fonction appelante ait declare et donc instancie
		 * un Zombie generique, en attendant de lui assigner les attributs copies
		 * sur le Zombie nouvellement cree dans le corps de la fonction "randomChump".
		 * Par ailleurs, dans le temps suivant l'instanciation de ce nouveau Zombie
		 * dans la fonction "randomChump" et precedant le retour de cette derniere,
		 * on compterait un Zombie de trop au compteur.
		 */
		Zombie	*randomChump(void) const;

	private:
		std::string			_zombie_type;
		static std::string const	_first_syllabs[30];
		static std::string const	_last_syllabs[29];
};

#endif
