#include <fstream>
#include <string>
#include <iostream>

static bool	ft_in_place(std::string const &filename, std::string const &s)
{
	std::ofstream	ofs;

	ofs.open(filename + ".replace", std::ios_base::out | std::ios_base::trunc);
	if (!(ofs.is_open()))
	{
		std::cout << "Failed to open file in write mode" << std::endl;
	}
	else
	{
		ofs << s;
		ofs.close();
		return (true);
	}
	return (false);
}

static bool	ft_sed(std::string const filename, std::ifstream &ifs, std::string const s1, std::string const s2)
{
	size_t			length;
	char			*buff;
	std::string		s;
	size_t			pos;

	ifs.seekg(0, ifs.end);
	length = (size_t)ifs.tellg();
	ifs.seekg(0, ifs.beg);
	buff = new char[length + 1];
	ifs.read(buff, length);
	buff[length] = '\0';
	s = buff;
	delete [] buff;
	pos = 0;
	while (!((pos = s.find(s1, pos + s2.length())) == std::string::npos))
	{
		/*
		std::cout << "s: " << s << std::endl;
		std::cout << "s1: " << s1 << std::endl;
		std::cout << "s2: " << s2 << std::endl;
		std::cout << "pos: " << pos << std::endl;
		std::cout << "length: " << length << std::endl;
		*/
		s.replace(pos, s1.length(), s2);
	}
	return (ft_in_place(filename, s) ? true : false);
}

int		main(int argc, char **argv)
{
	std::string	filename;
	std::ifstream	ifs;
	std::string	s1;
	std::string	s2;

	if (argc == 4)
	{
		filename = *(argv + 1);
		s1 = *(argv + 2);
		s2 = *(argv + 3);
		if (!(filename.length() > 0))
		{
			std::cout << "Invalid file name" << std::endl;
		}
		else if (!(s1.length() > 0 && s2.length() > 0))
		{
			std::cout << "Both of the 2 strings must not be empty" << std::endl;
		}
		else
		{
			ifs.open(filename, std::ifstream::in);
			if (!(ifs.is_open()))
			{
				std::cout << "Failed to open file in read mode" << std::endl;
			}
			else
			{
				ft_sed(filename, ifs, s1, s2);
				ifs.close();
			}
		}
	}
	else
	{
		std::cout << "usage: ./replace <filename> <sequence to replace> <sequence to be replaced by>" << std::endl;
	}
	return (0);
}
