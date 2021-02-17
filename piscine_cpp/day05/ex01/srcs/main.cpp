#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	Bureaucrat	jim("Jim", 2);
	Bureaucrat	bob("Bob", 149);
	Form		f("A38", 1);

	std::cout << jim << std::endl;
	std::cout << bob << std::endl;
	std::cout << f << std::endl;

	try
	{
		f.beSigned(jim);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	jim.incrementGrade();
	bob.decrementGrade();

	std::cout << jim << std::endl;
	std::cout << bob << std::endl;
	std::cout << f << std::endl;

	try
	{
		//f.beSigned(jim);
		jim.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << f << std::endl;

	return (0);
}
