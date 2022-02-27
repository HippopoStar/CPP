/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:27:47 by lcabanes          #+#    #+#             */
/*   Updated: 2022/02/27 21:27:50 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		ScalarConverter my_converter(argv[1]);

		std::cout << my_converter;
	}
	else
	{
		std::cout << "usage: " << argv[0] << "<litteral>" << std::endl;
	}

	return (0);
}
