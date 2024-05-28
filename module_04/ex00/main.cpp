/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:19:30 by marde-vr          #+#    #+#             */
/*   Updated: 2024/05/28 09:30:04 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*meta;
	const Animal	*j;
	const Animal	*i;

	meta = new Animal();
	j = new Dog();
	i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	delete meta;
	delete j;
	delete i;



	const WrongAnimal	*wrongMeta;
	const WrongAnimal	*wrongCat1;
	const WrongCat		*wrongCat2;

	wrongMeta = new WrongAnimal();
	wrongCat1 = new WrongCat();
	wrongCat2 = new WrongCat();
	std::cout << wrongCat1->getType() << " " << std::endl;
	wrongMeta->makeSound(); //will NOT output the cat sound!
	wrongCat1->makeSound(); //will NOT output the cat sound!
	wrongCat2->makeSound();
	delete wrongMeta;
	delete wrongCat1;
	delete wrongCat2;
	return (0);
}
