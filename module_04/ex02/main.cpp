/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:19:30 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/10 08:56:17 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	int size = 10;
	Animal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < size; i++)
		delete animals[i];

	std::cout << std::endl << std::endl << std::endl;

	Dog dog1 = Dog();
	Dog dog2 = Dog();
	dog2 = dog1;
	Dog dog3 = Dog(dog1);
	dog1._brain->_ideas[0] = "I should eat some food!";
	std::cout << "dog1: " << dog1._brain->_ideas[0] << std::endl;
	std::cout << "dog2: " << dog2._brain->_ideas[0] << std::endl;
	std::cout << "dog3: " << dog3._brain->_ideas[0] << std::endl;

	//Animal test;

	return (0);
}
