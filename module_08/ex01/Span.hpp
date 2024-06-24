/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:08:45 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/24 15:56:46 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _vect;
	
	public:
		Span();
		Span(unsigned int N);
		Span(Span& cp);
		Span& operator=(Span& other);
		~Span();

		void			addNumber(int nb);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class SpanIsFullException: public std::exception
		{
			public:
				const char	*what(void) throw();
		};
		class SpanIsImpossibleException: public std::exception
		{
			public:
				const char	*what(void) throw();
		};
};

#endif
