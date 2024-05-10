/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:51:35 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/10 13:28:38 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(), _y() {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}

Point::Point(const Point& p)
{
	*this = p;
}

Point& Point::operator=(const Point& p)
{
	_x = p._x;
	_y = p._y;
	return *this;
}

Point::~Point() {}
