#include <ctime>
#include <cstdlib>
#include <iostream>
#include "FragTrap.hpp"

int		main(void)
{
	std::string	name_01("BeerCan");
	std::string	name_02("ShoesBox");
	FragTrap	frag_trap_01(name_01);
	FragTrap	frag_trap_02(name_02);

	srand(time(NULL));

	std::cout << frag_trap_01 << std::endl;
	std::cout << frag_trap_02 << std::endl;

	frag_trap_01.vault_hunter_dot_exe(name_02);
	frag_trap_02.rangedAttack(name_01);
	frag_trap_01.takeDamage(20);
	frag_trap_01.meleeAttack(name_02);
	frag_trap_02.takeDamage(30);
	frag_trap_01.vault_hunter_dot_exe(name_02);
	frag_trap_01.beRepaired(20);
	frag_trap_02.beRepaired(20);

	std::cout << frag_trap_01 << std::endl;
	std::cout << frag_trap_02 << std::endl;

	return (0);
}
