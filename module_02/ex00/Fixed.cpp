/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:42:59 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/08 17:48:07 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->rawValue = 0;
}

Fixed::Fixed(Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	rawValue = copy.getRawBits();
}

Fixed Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called\n";
	rawValue = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return rawValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	rawValue = raw;
}
