#include <iostream>
#include <string>

int		main(int argc, char **argv)
{
	int		i;
	size_t		j;
	std::string	s;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			s = *(argv + i);
			j = 0;
			while (j < s.length())
			{
				if ('a' <= s.at(j) && s.at(j) <= 'z')
				{
					s.at(j) = s.at(j) + ('A' - 'a');
				}
				j++;
			}
			std::cout << s;
			i++;
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
	return (0);
}
