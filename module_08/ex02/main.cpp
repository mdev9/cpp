/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:01:02 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/26 13:15:00 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl; // 3
	mstack.pop();
	std::cout << mstack.size() << std::endl; // 1
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl; // 5 3 5 737 0
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

	
	MutantStack<int> mstack2;
	for (int i = 0; i < 10; i++)
		mstack2.push(i);
	MutantStack<int>::iterator it2 = mstack2.begin();
	MutantStack<int>::iterator ite2 = mstack2.end();
	while (it2 != ite2)
	{
		std::cout << *ite2 << std::endl;
		ite2--;
	}
	return 0;
}
