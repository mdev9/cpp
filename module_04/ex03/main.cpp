/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:45:54 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/10 10:55:48 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		MateriaSource* src1 = new MateriaSource();
		src1->learnMateria(new Ice());
		src1->learnMateria(new Cure());

		MateriaSource* src2 = new MateriaSource(*src1);
		AMateria* tmp1 = src2->createMateria("ice");
		std::cout << "src2 createMateria ice: " << tmp1->getType() << std::endl;
		AMateria* tmp2 = src2->createMateria("cure");
		std::cout << "src2 createMateria cure: " << tmp2->getType() << std::endl;
		delete tmp1;
		delete tmp2;

		MateriaSource src3;
		src3 = *src1;
		AMateria* tmp3 = src3.createMateria("ice");
		std::cout << "src3 createMateria ice: " << tmp3->getType() << std::endl;
		AMateria* tmp4 = src3.createMateria("cure");
		std::cout << "src3 createMateria cure: " << tmp4->getType() << std::endl;
		delete tmp3;
		delete tmp4;

		delete src1;
		delete src2;
		
		//std::cout << "Char1:\n";
		Character* char1 = new Character("char1");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		char1->equip(ice);
		char1->equip(cure);
		//char1->printInventory();

		//std::cout << "Char2:\n";
		Character* char2 = new Character(*char1);
		//char2->printInventory();
		char2->use(0, *char1); 
		char2->use(1, *char1);

		//std::cout << "Char3:\n";
		Character char3("char3");
		char3 = *char1;
		//char3.printInventory();
		char3.use(0, *char1);
		char3.use(1, *char1);
		
		delete char1;
		delete char2;
	}
    return 0;
}
