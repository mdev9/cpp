/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:42:59 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/09 12:23:31 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	_value = roundf(value * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _fractionalBits)); 
}

int	Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fp)
{
   return out << fp.toFloat();
}

Fixed::Fixed(const Fixed &fp)
{
	std::cout << "Copy constructor called\n";
	*this = fp;
}

Fixed& Fixed::operator=(const Fixed& fp) 
{
	std::cout << "Copy assignment operator called\n";
	_value = fp._value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return _value;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	_value = raw;
}
