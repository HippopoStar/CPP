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

ScalarConverter::ScalarConverter(void)
	: _litteral("default"), _scalar_type(ScalarConverter::TYPE_UNKNOWN)
{
	std::cout << "<ScalarConverter> Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string const &litteral)
	: _litteral(litteral)
{
	std::cout << "<ScalarConverter> Constructor called with parameter(s) [\"" << litteral << "\"]" << std::endl;
	if (is_character(litteral))
	{
		(*this)._scalar_type = ScalarConverter::TYPE_CHAR;
	}
	else if (is_integer(litteral))
	{
		(*this)._scalar_type = ScalarConverter::TYPE_INT;
	}
	else if (is_float(litteral))
	{
		(*this)._scalar_type = ScalarConverter::TYPE_FLOAT;
	}
	else if (is_double(litteral))
	{
		(*this)._scalar_type = ScalarConverter::TYPE_DOUBLE;
	}
	else
	{
		(*this)._scalar_type = ScalarConverter::TYPE_UNKNOWN;
	}
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
	: _litteral(src.getLitteral()), _scalar_type(src.getScalarType())
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
	//(*this)._scalar_type = rhs.getScalarType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, ScalarConverter const &rhs)
{
	o << "<" << rhs.getLitteral() << ">" << std::endl;
	rhs.display_scalar_type(o);
	rhs.display_conversion(o);
	return (o);
}

/**
 * Public method(s)
 */

std::string const	&ScalarConverter::getLitteral(void) const
{
	return ((*this)._litteral);
}

ScalarConverter::ScalarTypes	ScalarConverter::getScalarType(void) const
{
	return ((*this)._scalar_type);
}

std::string const	ScalarConverter::display_scalar_type(std::string const &litteral)
{
	std::ostringstream	oss;
	oss << std::boolalpha;
	oss << "is_character: " << ((is_character(litteral)) ? true : false) << std::endl;
	oss << "is_integer: " << ((is_integer(litteral)) ? true : false) << std::endl;
	oss << "is_float: " << ((is_float(litteral)) ? true : false) << std::endl;
	oss << "is_double: " << ((is_double(litteral)) ? true : false) << std::endl;
	return (oss.str());
}

void	ScalarConverter::display_scalar_type(std::ostream &o) const
{
	std::ostringstream	oss;
	oss << std::boolalpha;
	oss << "is_character: " << ((ScalarConverter::TYPE_CHAR == (*this)._scalar_type) ? true : false) << std::endl;
	oss << "is_integer: " << ((ScalarConverter::TYPE_INT == (*this)._scalar_type) ? true : false) << std::endl;
	oss << "is_float: " << ((ScalarConverter::TYPE_FLOAT == (*this)._scalar_type) ? true : false) << std::endl;
	oss << "is_double: " << ((ScalarConverter::TYPE_DOUBLE == (*this)._scalar_type) ? true : false) << std::endl;
	o << oss.str();
}

void	ScalarConverter::display_conversion(std::ostream &o) const
{
	char	c;
	int		n;
	float	f;
	double	d;

	o << "char: " << ((convert((*this)._litteral, c)) ? std::string(&c, 1) : "Non displayable") << std::endl;
	o << "int: " << ((convert((*this)._litteral, n)) ? std::to_string(n) : "impossible") << std::endl;
	o << "float: " << ((convert((*this)._litteral, f)) ? std::to_string(f) : "impossible") << std::endl;
	o << "double: " << ((convert((*this)._litteral, d)) ? std::to_string(d) : "impossible") << std::endl;
}

/*
** Note:
** User input characters are expected to be surrounded by '\'' to enable limit-cases distinction
** For instance:
** ./convert 0
** -> Must evaluate to "Non displayable" and not to '0', as regards the conversion into character
*/
bool	ScalarConverter::is_character(std::string const &litteral)
{
	return ((3 == litteral.length()
			&& '\'' == litteral.at(0)
			&& std::isprint(static_cast<int>(litteral.at(1)))
			&& '\'' == litteral.at(2))
		? true : false);
}

bool	ScalarConverter::is_integer(std::string const &litteral)
{
	size_t	i(0);

	if (litteral.length() > 0)
	{
		if (('+' == litteral.at(0) || '-' == litteral.at(0)) && litteral.length() > 1)
		{
			i++;
		}
		while (i < litteral.length()
			&& std::isdigit(litteral.at(i)))
		{
			i++;
		}
		if (litteral.length() == i)
		{
			return (true);
		}
	}
	return (false);
}

bool	ScalarConverter::is_float(std::string const &litteral)
{
	return (is_floating_point_notation(litteral, true));
}

bool	ScalarConverter::is_double(std::string const &litteral)
{
	return (is_floating_point_notation(litteral, false));
}

bool	ScalarConverter::convert(std::string const &litteral, char &c)
{
	if (is_character(litteral))
	{
		c = litteral.at(1);
		return (true);
	}
	else
	{
		int		n;
		float	f;
		double	d;

		if (is_integer(litteral) && convert(litteral, n) && std::isprint(n))
		{
			c = static_cast<char>(n);
			return (true);
		}
		else if (is_float(litteral) && convert(litteral, f) && std::isprint(static_cast<int>(f)))
		{
			c = static_cast<char>(f);
			return (true);
		}
		else if (is_double(litteral) && convert(litteral, d) && std::isprint(static_cast<int>(d)))
		{
			c = static_cast<char>(f);
			return (true);
		}
	}
	return (false);
}

bool	ScalarConverter::convert(std::string const &litteral, int &n)
{
	if (is_integer(litteral))
	{
		n = std::stoi(litteral);
		return (true);
	}
	else
	{
		char	c;
		float	f;
		double	d;

		if (is_character(litteral) && convert(litteral, c))
		{
			n = static_cast<int>(c);
			return (true);
		}
		else if (is_float(litteral) && convert(litteral, f))
		{
			n = static_cast<int>(f);
			return (true);
		}
		else if (is_double(litteral) && convert(litteral, d))
		{
			n = static_cast<int>(d);
			return (true);
		}
	}
	return (false);
}

bool	ScalarConverter::convert(std::string const &litteral, float &f)
{
	if (is_float(litteral))
	{
		f = std::stof(litteral);
		return (true);
	}
	else
	{
		char	c;
		int		n;
		double	d;

		if (is_character(litteral) && convert(litteral, c))
		{
			f = static_cast<float>(c);
			return (true);
		}
		else if (is_integer(litteral) && convert(litteral, n))
		{
			f = static_cast<float>(n);
			return (true);
		}
		else if (is_double(litteral) && convert(litteral, d))
		{
			f = static_cast<float>(d);
			return (true);
		}
	}
	return (false);
}

bool	ScalarConverter::convert(std::string const &litteral, double &d)
{
	if (is_double(litteral))
	{
		d = std::stod(litteral);
		return (true);
	}
	else
	{
		char	c;
		int		n;
		float	f;

		if (is_character(litteral) && convert(litteral, c))
		{
			d = static_cast<double>(c);
			return (true);
		}
		else if (is_integer(litteral) && convert(litteral, n))
		{
			d = static_cast<double>(n);
			return (true);
		}
		else if (is_float(litteral) && convert(litteral, f))
		{
			d = static_cast<double>(f);
			return (true);
		}
	}
	return (false);
}

/**
 * Private method(s)
 */

bool	ScalarConverter::is_floating_point_notation(std::string const &litteral, bool expect_trailing_f)
{
	bool	dot_found(false);
	size_t	litteral_length;
	size_t	number_length;
	size_t	i(0);

	litteral_length = litteral.length();
	if (!expect_trailing_f
		|| (litteral_length > 0
			&& 'f' == litteral.at(litteral_length - 1)))
	{
		number_length = expect_trailing_f ? litteral_length - 1 : litteral_length;
		if (number_length > 0
			&& ('+' == litteral.at(0)
				|| '-' == litteral.at(0)))
		{
			i++;
		}
		if (!std::string("nan").compare(expect_trailing_f ? litteral.substr(0, number_length) : litteral)
			|| !std::string("inf").compare(expect_trailing_f ? litteral.substr(i, number_length) : litteral))
		{
			return (true);
		}
		else if (i < number_length && std::isdigit(litteral.at(i)))
		{
			while (i < number_length)
			{
				if (!(std::isdigit(litteral.at(i))
						|| ('.' == litteral.at(i)
							&& (false == dot_found))))
				{
					return (false);
				}
				if ('.' == litteral.at(i))
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
		else
		{
			return (false);
		}
	}
	return (false);
}
