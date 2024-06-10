/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:19:30 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/10 10:59:09 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
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
	}
	std::cout << std::endl << std::endl << std::endl;
	{
		Dog *dog1 = new Dog;
		Dog *dog2 = new Dog;
		*dog2 = *dog1;
		Dog *dog3 = new Dog(*dog1);
		dog1->setIdea("I should eat some food!", 0);
		std::cout << "dog1: " << dog1->getIdea(0) << std::endl;
		std::cout << "dog2: " << dog2->getIdea(0) << std::endl;
		std::cout << "dog3: " << dog3->getIdea(0) << std::endl;
		delete dog1;
		delete dog2;
		delete dog3;
	}
	std::cout << std::endl << std::endl << std::endl;
	{
		Cat *cat1 = new Cat;
		Cat *cat2 = new Cat;
		*cat2 = *cat1;
		Cat *cat3 = new Cat(*cat1);
		cat1->setIdea("I should eat some food!", 0);
		std::cout << "cat1: " << cat1->getIdea(0) << std::endl;
		std::cout << "cat2: " << cat2->getIdea(0) << std::endl;
		std::cout << "cat3: " << cat3->getIdea(0) << std::endl;
		delete cat1;
		delete cat2;
		delete cat3;
	}
	return (0);
}
