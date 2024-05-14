/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:42:59 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/14 13:45:55 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called\n";
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called\n";
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called\n";
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fp)
{
	//std::cout << "Copy constructor called\n";
	*this = fp;
}

Fixed& Fixed::operator=(const Fixed& fp) 
{
	//std::cout << "Copy assignment operator called\n";
	_value = fp._value;
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called\n";
}




bool	Fixed::operator>(const Fixed& fp)
{
	return (_value > fp._value);
}

bool	Fixed::operator<(const Fixed& fp)
{
	return (_value < fp._value);
}

bool	Fixed::operator>=(const Fixed& fp)
{
	return (_value >= fp._value);
}

bool	Fixed::operator<=(const Fixed& fp)
{
	return (_value <= fp._value);
}

bool	Fixed::operator==(const Fixed& fp)
{
	return (_value == fp._value);
}

bool	Fixed::operator!=(const Fixed& fp)
{
	return (_value != fp._value);
}




int	Fixed::operator+(const Fixed& fp)
{
	return (_value + fp._value);
}

int	Fixed::operator-(const Fixed& fp)
{
	return (_value - fp._value);
}

Fixed	Fixed::operator*(const Fixed& fp)
{
	return (this->toFloat() * fp.toFloat());
}

Fixed	Fixed::operator/(const Fixed& fp)
{
	return (this->toFloat() / fp.toFloat());
}




Fixed& Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed& Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--(*this);
	return tmp;
}




Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}




int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called\n";
	return _value;
}

void Fixed::setRawBits(const int raw)
{
	//std::cout << "setRawBits member function called\n";
	_value = raw;
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
