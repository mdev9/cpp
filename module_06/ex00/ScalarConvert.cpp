/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:09:04 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/19 12:48:27 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
#include <cstdlib>
#include <limits.h>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &cp)
{
	(void) cp;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter &other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool isFloat(const std::string& str) {
    char* end;
    std::strtof(str.c_str(), &end);
    return *end == 'f' && *(end + 1) == 0;
}

bool isDouble(const std::string& str) {
    char* end;
    std::strtod(str.c_str(), &end);
    return *end == 0;
}

void ScalarConverter::convert(std::string literal)
{
	bool	is_float = isFloat(literal);
	bool	is_double = isDouble(literal);
	int		nbInt = atoi(literal.c_str());
	double	nbDouble = atof(literal.c_str());
	float	nbFloat = static_cast<float>(nbDouble);
	
	if (!nbDouble && literal[0] >= 32 && literal[0] <= 126)
	{
		std::cout << "char: '" << literal[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
		return;
	}
	else if (nbInt >= 32 && nbInt <= 126)
		std::cout << "char: '" << static_cast<char>(nbInt) << "'" << std::endl;
	else if (nbDouble >= 0 && nbDouble <= 255)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (nbDouble < INT_MAX && nbDouble > INT_MIN)
		std::cout << "int: " << nbInt << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (literal == "+inf" || literal =="inff" || literal == "-inf" || literal == "nan")
	{
		std::cout << "float: " << literal << 'f' << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
	else if (literal == "+inff" || literal == "inff" || literal == "-inff" || literal == "nanf")
	{
		std::cout << "float: " << literal << std::endl;
		literal[literal.length() - 1] = 0;
		std::cout << "double: " << literal << std::endl;
	}
	else
	{
		std::cout << "float: " << nbFloat;
		if (is_float || nbFloat == static_cast<int>(nbFloat))
			std::cout << ".0";
		std::cout << 'f' << std::endl;

		std::cout << "double: " << nbDouble;
		if (is_double || nbDouble == static_cast<int>(nbDouble))
			std::cout << ".0";
		std::cout << std::endl;
	}
}
