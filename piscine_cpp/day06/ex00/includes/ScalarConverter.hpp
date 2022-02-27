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
# include <cctype>

class	ScalarConverter
{

	public:

		ScalarConverter(std::string const &litteral);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);

		std::string const	&getLitteral(void) const;

		bool is_character(void) const;
		bool is_integer(void) const;
		bool is_float(void) const;
		bool is_double(void) const;

	private:
		ScalarConverter(void);
		ScalarConverter		&operator=(ScalarConverter const &rhs);

		bool is_floating_point_notation(bool expect_trailing_f) const;


		std::string const		_litteral;

};

std::ostream	&operator<<(std::ostream &o, ScalarConverter const &rhs);

#endif
