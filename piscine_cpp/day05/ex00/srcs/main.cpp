#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat	jim("Jim", 1);
	Bureaucrat	bob("Bob", 150);

	std::cout << jim << std::endl;
	std::cout << bob << std::endl;

	try
	{
		jim.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		bob.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	moi("Moi", 9001);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	jim.decrementGrade();
	bob.incrementGrade();

	std::cout << jim << std::endl;
	std::cout << bob << std::endl;

	return (0);
}
