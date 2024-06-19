/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:12:17 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/19 10:45:07 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int random = std::rand() % 3;

	if (!random)
	{
		std::cout << "Generated an object of type A" << std::endl;
		return (new A);
	}
	else if (random == 1)
	{
		std::cout << "Generated an object of type B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Generated an object of type C" << std::endl;
		return (new C);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object is of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object is of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object is of type C" << std::endl;
	else
		std::cout << "Object is of unknown type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Object is of type A" << std::endl;
		(void) a;
		return;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "Object is not of type A" << std::endl;
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Object is of type B" << std::endl;
		(void) b;
		return;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "Object is not of type B" << std::endl;
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Object is of type C" << std::endl;
		(void) c;
		return;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "Object is not of type C" << std::endl;
	}
}

int	main(void)
{
	std::srand(std::time(0) * 1000 + getpid());

	for (int i = 0; i < 10; i++)
		identify(generate());
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		identify(*generate());
}
