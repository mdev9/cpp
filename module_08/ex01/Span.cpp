/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:31:44 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/24 16:08:19 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N): _N(N) {}

Span::Span(Span& cp)
{
	*this = cp;
}

Span& Span::operator=(Span& other)
{
	_N = other._N;
	_vect = other._vect;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int nb)
{
	if (_N <= _vect.size())
		throw SpanIsFullException();
	_vect.push_back(nb);
}

unsigned int	Span::getSpan()

unsigned int	Span::shortestSpan()
{
	int shortestSpan = _vect[0];
	for (int i = 0; i < _vect.size() / 2; i++)
	{
		for (int j = 0; j < _vect.size(); j++)
		{

		}
	}

}

unsigned int	Span::longestSpan()
{

}

const char *Span::SpanIsFullException::what(void) throw()
{
	return "Span is full!";
}

const char *Span::SpanIsImpossibleException::what(void) throw()
{
	return "Span is impossible!";
}
