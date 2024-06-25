/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:31:44 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/25 09:30:07 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0) {}

Span::Span(unsigned int N): _N(N) {}

Span::Span(const Span& cp)
{
	*this = cp;
}

Span& Span::operator=(const Span& other)
{
	_N = other._N;
	_numbers = other._numbers;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int nb)
{
	if (_numbers.size() >= _N)
		throw SpanIsFullException();
	_numbers.push_back(nb);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + _numbers.size() > _N)
		throw SpanIsFullException();
	_numbers.insert(_numbers.end(), begin, end);
}

unsigned int	Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw SpanIsImpossibleException();

	int	currSpan = std::abs(_numbers[0] - _numbers[1]);
	int shortestSpan = currSpan;

	for (unsigned int i = 0; i < _numbers.size(); i++)
	{
		for (unsigned int j = i + 1; j < _numbers.size(); j++)
		{
			currSpan = std::abs(_numbers[i] - _numbers[j]);
			if (currSpan < shortestSpan)
				shortestSpan = currSpan;
		}
	}
	return shortestSpan;
}

unsigned int	Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw SpanIsImpossibleException();

	int	currSpan = std::abs(_numbers[0] - _numbers[1]);
	int longestSpan = currSpan;

	for (unsigned int i = 0; i < _numbers.size(); i++)
	{
		for (unsigned int j = 0; j < _numbers.size(); j++)
		{
			currSpan = std::abs(_numbers[i] - _numbers[j]);
			if (currSpan > longestSpan)
				longestSpan = currSpan;
		}
	}
	return longestSpan;
}

const char *Span::SpanIsFullException::what(void) throw()
{
	return "Span is full!";
}

const char *Span::SpanIsImpossibleException::what(void) throw()
{
	return "Span is impossible!";
}
