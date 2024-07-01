/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:51:21 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/01 11:07:48 by marde-vr         ###   ########.fr       */
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

int	charToInt(char c)
{
	return (c - 48);
}

bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
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

//remove this
#include <iostream>
void printStack(std::stack<char> st)
{
    while (!st.empty()) {
		std::cout << st.top() << " ";
        st.pop();
    }
	std::cout << std::endl;
}

int	RPN::calculate()
{
	char	token = 0;
	char	operand1 = 0;
	char	operand2 = 0;

	std::stack<char> tempStack;
    while (!stack.empty()) {
        tempStack.push(stack.top());
        stack.pop();
    }
    stack = tempStack;
	printStack(stack);

	if (isOperator(stack.top()))
		throw ErrorException();
	operand1 = stack.top();
	stack.pop();
	if (isOperator(stack.top()))
		throw ErrorException();
	operand2 = stack.top();
	stack.pop();
	
	while (!stack.empty())
	{
		if (isOperator(stack.top()))
		{
			if (token)
				throw ErrorException();
			token = stack.top();
			stack.pop();
			std::cout << token << ", " << operand1 << ", " << operand2 << std::endl;
		}
		else
			throw ErrorException();
		if (!stack.empty())
		{
			if (isOperator(stack.top()))
				throw ErrorException();
			else
			{
				operand2 = stack.top();
				stack.pop();
			}
		}

		if (token == '+')
			operand1 = charToInt(operand1) + charToInt(operand2) + 48;
		else if (token == '-')
			operand1 = charToInt(operand1) - charToInt(operand2) + 48;
		else if (token == '*')
			operand1 = charToInt(operand1) * charToInt(operand2) + 48;
		else if (token == '/' && charToInt(operand2))
			operand1 = charToInt(operand1) / charToInt(operand2) + 48;
		else
			throw ErrorException();
	}
	if (operand1 && operand2 && !token)
		throw ErrorException();
	return charToInt(operand1);
}
