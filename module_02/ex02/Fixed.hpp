/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:43:19 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/09 13:24:34 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	int					_value;
	static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& fp);
		Fixed& operator=(const Fixed& fp);
		~Fixed();

		int operator>(const Fixed& fp);
		int operator<(const Fixed& fp);
		int operator>=(const Fixed& fp);
		int operator<=(const Fixed& fp);
		int operator==(const Fixed& fp);
		int operator!=(const Fixed& fp);

		int operator+(const Fixed& fp);
		int operator-(const Fixed& fp);
		int operator*(const Fixed& fp);
		int operator/(const Fixed& fp);

		Fixed& operator++();
		Fixed& operator--();
		Fixed& operator++(int);
		Fixed& operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fp);

#endif
