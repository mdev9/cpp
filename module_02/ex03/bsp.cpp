/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:25 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/14 14:02:45 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
Fixed sign(Point p1, Point p2, Point p3)
{
    return (p1.getX() - p3.getX() * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed fp1, fp2, fp3;
    bool has_neg, has_pos;

    fp1 = sign(point, a, b);
    fp2 = sign(point, b, c);
    fp3 = sign(point, c, a);

    has_neg = (fp1 < 0) || (fp2 < 0) || (fp3 < 0);
    has_pos = (fp1 > 0) || (fp2 > 0) || (fp3 > 0);

    return !(has_neg && has_pos);
}*/

float area(Point p1, Point p2, Point p3)
{
   return (std::abs((p1.getX()*(p2.getY()-p3.getY()) + p2.getX()*(p3.getY()-p1.getY())+ p3.getX()*(p1.getY()-p2.getY()))/2.0));
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
