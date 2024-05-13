/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:42:41 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/11 10:49:25 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);


int	main(void)
{
	{
	/*
	Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
	Expected Output: True
	Explanation:
				  B(10,30)
					/ \
				   /   \
				  /     \
				 /   P   \      
				/         \
		 A(0,0) ----------- C(20,0) 

	*/

		Point	a(Fixed(0), Fixed(0));
		Point	b(Fixed(10), Fixed(30));
		Point	c(Fixed(20), Fixed(0));
		Point	p(Fixed(10), Fixed(15));

		std::cout << bsp(a, b, c, p) << std::endl;
	}
	{
	/*
	Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
	Expected Output: False
	Explanation:
				  B(10,30)
					/ \
				   /   \
				  /     \
				 /       \      P
				/         \
		 A(0,0) ----------- C(20,0) 
	*/

		Point	a(Fixed(0), Fixed(0));
		Point	b(Fixed(10), Fixed(30));
		Point	c(Fixed(20), Fixed(0));
		Point	p(Fixed(30), Fixed(15));

		std::cout << bsp(a, b, c, p) << std::endl;
	}
	return (0);
}
