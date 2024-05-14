/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:42:41 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/14 14:03:21 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);


int	main(void)
{
	{
	/*
	Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
	Expected Output: True (Inside)
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

		if (bsp(a, b, c, p))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Not inside" << std::endl;
	}
	{
	/*
	Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
	Expected Output: False (Not inside)
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

		if (bsp(a, b, c, p))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Not inside" << std::endl;
	}
	{
	/*
	Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 0)
	Expected Output: False (Not inside)
	Explanation:
				  B(10,30)
					/ \
				   /   \
				  /     \
				 /       \      
				/         \
		 A(0,0) -----P----- C(20,0) 
	*/

		Point	a(Fixed(0), Fixed(0));
		Point	b(Fixed(10), Fixed(30));
		Point	c(Fixed(20), Fixed(0));
		Point	p(Fixed(10), Fixed(0));

		if (bsp(a, b, c, p))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Not inside" << std::endl;
	}
	return (0);
}
