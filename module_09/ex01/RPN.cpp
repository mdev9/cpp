/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:51:21 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/01 07:45:24 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

RPN::RPN()
{
	throw RPN::ErrorException();
}

RPN::RPN(RPN& cp)
{
	*this = cp;
}

RPN& RPN::operator=(RPN& other)
{
	stack = other.stack;
	return *this;
}

RPN::~RPN() {}

const char *RPN::ErrorException::what(void) throw()
{
	return "Error";
}

bool	isCharValid(char c)
{
	return ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '/' || c == '*');
}

RPN::RPN(std::string args)
{
	for (int i = 0; args[i]; i++)
	{
		if (args[i] == ' ')
			continue;
		if (isCharValid(args[i]) && (!args[i + 1] || args[i + 1] == ' '))
			stack.push(args[i]);
		else
			throw ErrorException();
	}
}

int	RPN::calculate()
{
	char	token;
	int		operand1;
	int		operand2;

	while (!stack.empty())
	{
		if (!operand1)
		{
			operand1 = stack.top();
			stack.pop();
		}

	}
}
