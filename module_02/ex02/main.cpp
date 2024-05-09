/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:42:41 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/09 13:33:49 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl << std::endl;

	Fixed b;

	std::cout << b << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << ++b << std::endl;
		std::cout << b << std::endl;
	}


	/*
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
*/
	return (0);
}
