/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:43:19 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/09 12:17:10 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	int					_value;
	static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& fp);
		Fixed& operator=(const Fixed& fp);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
