/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:08:30 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/25 09:34:55 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	// Span is full exception
	// Span is impossible exception with 0 numbers
	// Span is impossible exception with 1 number
	
	{

	}
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	int more_numbers_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> more_numbers(more_numbers_array, more_numbers_array + 10);
	Span sp2(15);
	sp2.addNumbers(more_numbers.begin(), more_numbers.end());
	sp2.addNumber(15);
	std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	return 0;
}
