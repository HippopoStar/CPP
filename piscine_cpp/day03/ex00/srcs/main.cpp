#include <ctime>
#include <cstdlib>
#include <iostream>
#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	frag_trap_01("Robot");
	FragTrap	frag_trap_02("ShoesBox");

	std::cout << frag_trap_01 << std::endl;
	std::cout << frag_trap_02 << std::endl;

	frag_trap_01.vault_hunter_dot_exe("ShoesBox");
	return (0);
}
