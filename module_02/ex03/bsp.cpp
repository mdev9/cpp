/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:25 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/14 14:36:19 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float ft_abs(float nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

float area(Point p1, Point p2, Point p3)
{
   return (ft_abs(
	 (p1.getX() * (p2.getY() - p3.getY())
	+ p2.getX() * (p3.getY() - p1.getY())
	+ p3.getX() * (p1.getY() - p2.getY())) / 2.0));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = Fixed(area(a, b, c));
	Fixed A1 = Fixed(area(point, b, c));
	Fixed A2 = Fixed(area(a, point, c));
	Fixed A3 = Fixed(area(a, b, point));

	if (A1 == 0 || A2 == 0 || A3 == 0)
		return (0);
	return (A.getRawBits() != A1.getRawBits() + A2.getRawBits() + A3.getRawBits());
}
