/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:08:45 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/25 11:19:29 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& cp);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int nb);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class SpanIsFullException: public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class SpanIsImpossibleException: public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

#endif
