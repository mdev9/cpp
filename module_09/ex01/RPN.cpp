/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:51:21 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/01 13:46:34 by marde-vr         ###   ########.fr       */
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

const char *RPN::ErrorException::what(void) const throw()
{
	return "Error";
}

bool	isCharValid(char c)
{
	return ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '/' || c == '*');
}

bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

int	RPN::popTop()
{
	int res;
	res = stack.top();
	stack.pop();
	return res;
}

#include <iostream>
void	printStack(std::stack<int> s)
{
	if (s.empty())
		return;
	int x = s.top();
	s.pop();
	printStack(s);
	std::cout << x << " ";
	s.push(x);
}

RPN::RPN(std::string args)
{
	for (int i = 0; args[i]; i++)
	{
		char c = args[i];
		if (c == ' ')
			continue;
		if (isCharValid(c) && (!args[i + 1] || args[i + 1] == ' '))
		{
			if (isOperator(c))
			{
				std::cout << c << std::endl;
				if (stack.size() < 2)
					throw ErrorException();
				if (c == '+')
					stack.push(popTop() + popTop());
				if (c == '-')
				{
					int tmp = popTop();
					stack.push(popTop() - tmp);
				}
				if (c == '*')
					stack.push(popTop() * popTop());
				if (c == '/')
					stack.push(popTop() / popTop());
			}
			else
				stack.push(c - 48);
			printStack(stack);
			std::cout << std::endl;
		}
		else
			throw ErrorException();
	}
}

int	RPN::getRes()
{
	return stack.top();
}
