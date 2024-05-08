/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:43:19 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/08 17:33:22 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	int					rawValue;
	static const int	fractional_bits_nb = 8;

	public:
		Fixed();
		Fixed(Fixed &copy);
		Fixed operator=(const Fixed &copy);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
