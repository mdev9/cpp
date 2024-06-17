/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:09:04 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/17 14:11:39 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
#include <cstdlib>
#include <sstream>

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

static int stoi( std::string & s ) {
    int i;
    std::istringstream(s) >> i;
    return i;
}

void ScalarConverter::convert(std::string literal)
{
	int integer = atoi(literal.c_str());
	if (integer >= 32 && integer <= 126)
		std::cout << "char: " << integer << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	//std::cout << "int: " << atoi(literal.c_str()) << std::endl;
	std::cout << "int: " << stoi(literal) << std::endl;
	std::cout << "float: " << std::endl;
	std::cout << "double: " << atof(literal.c_str()) << std::endl;
}

