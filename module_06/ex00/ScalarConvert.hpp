/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:09:21 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/17 08:05:24 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#include <iostream>

class ScalarConverter
{
	public:
		static void convert(std::string literal);
		ScalarConverter();
		ScalarConverter(ScalarConverter &cp);
		ScalarConverter& operator=(ScalarConverter &other);
		~ScalarConverter();
};

#endif
