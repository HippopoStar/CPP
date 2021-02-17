#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void)
{
	Bureaucrat	jim("Jim", 2);
	Bureaucrat	bob("Bob", 149);
	Form		f("A38", 1);

	Form		*shrubbery_form;

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
		f.beSigned(jim);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << f << std::endl;

	/* _____ _____ _____ _____ _____ _____ */

	shrubbery_form = new ShrubberyCreationForm("test.txt");
	try
	{
		jim.signForm(*shrubbery_form);
		//shrubbery_form->beSigned(jim);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	shrubbery_form->execute(jim);
	delete shrubbery_form;

	return (0);
}
