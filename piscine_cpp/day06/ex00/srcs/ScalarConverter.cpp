/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 23:04:16 by lcabanes          #+#    #+#             */
/*   Updated: 2022/02/27 23:04:25 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
 * Non-member attribute(s) initialization
 */

/**
 * Constructor(s) & Destructor(s)
 */

ScalarConverter::ScalarConverter(void) : _litteral("default")
{
	std::cout << "<ScalarConverter> Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string const &litteral) : _litteral(litteral)
{
	std::cout << "<ScalarConverter> Constructor called with parameter(s) [\"" << litteral << "\"]" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) : _litteral(src.getLitteral())
{
	std::cout << "<ScalarConverter> Copy constructor called" << std::endl;
	//*this = src;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "<ScalarConverter> Destructor called" << std::endl;
}

/**
 * Operator overload(s)
 */

ScalarConverter		&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	std::cout << "<ScalarConverter> Assignement operator called" << std::endl;
	(void)rhs;
	//(*this)._litteral = rhs.getLitteral();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, ScalarConverter const &rhs)
{
	o << "<" << rhs.getLitteral() << ">" << std::endl;
	o << std::boolalpha;
	o << "is_character: " << rhs.is_character() << std::endl;
	o << "is_integer: " << rhs.is_integer() << std::endl;
	o << "is_float: " << rhs.is_float() << std::endl;
	o << "is_double: " << rhs.is_double() << std::endl;
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&ScalarConverter::getLitteral(void) const
{
	return ((*this)._litteral);
}

/*
** Note:
** User input characters are expected to be surrounded by '\'' to enable limit-cases distinction
** For instance:
** ./convert 0
** -> Must evaluate to "Non displayable" and not to '0', as regards the conversion into character
*/
bool	ScalarConverter::is_character(void) const
{
	return ((3 == (*this)._litteral.length()
			&& '\'' == (*this)._litteral.at(0)
			&& std::isprint((int)(*this)._litteral.at(1))
			&& '\'' == (*this)._litteral.at(2))
		? true : false);
}

bool	ScalarConverter::is_integer(void) const
{
	size_t	i(0);

	if ((*this)._litteral.length() > 0)
	{
		while (i < (*this)._litteral.length()
			&& std::isdigit((*this)._litteral.at(i)))
		{
			i++;
		}
		if ((*this)._litteral.length() == i)
		{
			return (true);
		}
	}
	return (false);
}

bool	ScalarConverter::is_float(void) const
{
	return (is_floating_point_notation(true));
}

bool	ScalarConverter::is_double(void) const
{
	return (is_floating_point_notation(false));
}

/**
 * Private method(s)
 */

bool	ScalarConverter::is_floating_point_notation(bool expect_trailing_f) const
{
	bool	dot_found(false);
	size_t	litteral_length;
	size_t	number_length;
	size_t	i(0);

	litteral_length = (*this)._litteral.length();
	if (!expect_trailing_f
		|| (litteral_length > 0
			&& 'f' == (*this)._litteral.at(litteral_length - 1)))
	{
		number_length = expect_trailing_f ? litteral_length - 1 : litteral_length;
		if (number_length > 0
			&& ('+' == (*this)._litteral.at(0)
				|| '-' == (*this)._litteral.at(0)))
		{
			i++;
		}
		if (std::isdigit((*this)._litteral.at(i)))
		{
			while (i < number_length)
			{
				if (!(std::isdigit((*this)._litteral.at(i))
						|| ('.' == (*this)._litteral.at(i)
							&& (false == dot_found))))
				{
					return (false);
				}
				if ('.' == (*this)._litteral.at(i))
				{
					dot_found = true;
				}
				i++;
			}
			if (i == number_length && dot_found)
			{
				return (true);
			}
		}
	}
	return (false);
}
