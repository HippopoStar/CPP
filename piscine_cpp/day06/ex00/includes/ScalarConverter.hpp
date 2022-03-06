/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:28:01 by lcabanes          #+#    #+#             */
/*   Updated: 2022/02/27 21:28:03 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cctype>

class	ScalarConverter
{

	public:

		ScalarConverter(std::string const &litteral);
		~ScalarConverter(void);

		std::string const	&getLitteral(void) const;

		void	display_scalar_type(std::ostream &o) const;
		void	display_conversion(std::ostream &o) const;

		static std::string const	display_scalar_type(std::string const &litteral);

		static bool	is_character(std::string const &litteral);
		static bool	is_integer(std::string const &litteral);
		static bool	is_float(std::string const &litteral);
		static bool	is_double(std::string const &litteral);

		static bool	convert(std::string const &litteral, char &c);
		static bool	convert(std::string const &litteral, int &n);
		static bool	convert(std::string const &litteral, float &f);
		static bool	convert(std::string const &litteral, double &d);

	private:

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter		&operator=(ScalarConverter const &rhs);

		enum ScalarTypes:	std::uint8_t
		{
			TYPE_UNKNOWN,
			TYPE_CHAR,
			TYPE_INT,
			TYPE_FLOAT,
			TYPE_DOUBLE
		};

		ScalarTypes	getScalarType(void) const;

		static bool	is_floating_point_notation(std::string const &litteral, bool expect_trailing_f);

		std::string const		_litteral;
		ScalarTypes				_scalar_type;

};

std::ostream	&operator<<(std::ostream &o, ScalarConverter const &rhs);

#endif
