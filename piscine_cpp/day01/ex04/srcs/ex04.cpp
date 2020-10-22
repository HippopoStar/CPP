#include <iostream>
#include <string>

int		main(void)
{
	std::string const	s("HI THIS IS BRAIN");
	std::string const	*p = &s;
	std::string const	&r = s;

	std::cout << *p << std::endl;
	std::cout << r << std::endl;
	return (0);
}
