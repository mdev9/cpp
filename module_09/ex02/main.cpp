/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:12:59 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/03 10:26:24 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iostream>

std::list<int> createPairs(std::list<int> lst)
{
	std::list<int> splitLst;
	std::list<int> tmpLst;

	for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i)
	{
		tmpSize = tmpLst.size();
		
	}
}

std::list<int> mergeInsertionSort(std::list<int> lst)
{
	bool isOdd = lst.size() % 2;
	if (isOdd)
	{
		int straggler = lst.back();
		lst.pop_back();
	}

	//split lst
	
	//sort splited lst
	
	//recursively sort the pairs by their largest element
	
	std::list<int> sortedLst = //create lst

	return sortedLst;
}

int	main(int argc, char **argv)
{
	std::list<int> lst;
	std::list<int> sortedLst;

	std::cout << "Before:\t";
	for (int i = 1; i < argc; i++)
	{
		std::cout << ' ' << argv[i];
		lst.push_back(atoi(argv[i]));
	}
	std::cout << std::endl;

	sortedLst = mergeInsertionSort(lst);

	std::cout << "After:\t";
	for (std::list<int>::iterator i = sortedLst.begin(); i != sortedLst.end(); ++i)
		std::cout << ' ' << *i;
	std::cout << std::endl;
	
}
