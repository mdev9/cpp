/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:25 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/11 10:39:23 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

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
}
