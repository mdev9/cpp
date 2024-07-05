/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:25:26 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/05 11:13:26 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <utility>

PmergeMe::PmergeMe(): original(0) {}

PmergeMe::PmergeMe(const std::vector<int>& input) : original(input) {}

PmergeMe::PmergeMe(PmergeMe& cp)
{
	*this = cp;
}

PmergeMe& PmergeMe::operator=(PmergeMe& other)
{
	original = other.original;
	sorted_vector = other.sorted_vector;
	sorted_list = other.sorted_list;
	vectorTime = other.vectorTime;
	listTime = other.listTime;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort()
{
    sorted_vector = original;
    sorted_list.assign(original.begin(), original.end());

    clock_t start = clock();
    mergeInsertSort(sorted_vector);
    clock_t end = clock();
    vectorTime = double(end - start) / (CLOCKS_PER_SEC / 1000000);

    start = clock();
    mergeInsertSort(sorted_list);
    end = clock();
    listTime = double(end - start) / (CLOCKS_PER_SEC / 1000000);
}

void PmergeMe::displayBefore() const
{
    std::cout << "Before:\t";
    for (size_t i = 0; i < original.size(); ++i)
        std::cout << original[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
    std::cout << "After:\t";
    for (size_t i = 0; i < sorted_vector.size(); ++i)
        std::cout << sorted_vector[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::displayTimes() const
{
    std::cout << "Time to process a range of " << original.size() << " elements with std::vector: " << vectorTime << " microseconds\n";
    std::cout << "Time to process a range of " << original.size() << " elements with std::list: " << listTime << " microseconds\n";
}

template <typename Container>
std::vector<std::pair<int, int> > create_pairs(const Container& container)
{
    std::vector<std::pair<int, int> > splitArray;
	typename Container::const_iterator it = container.begin();
	while (it != container.end())
	{
		int first = *it;
		++it;
		if (it != container.end())
		{
			int second = *it;
			++it;
			splitArray.push_back(std::make_pair(first, second));
		}
		else
			splitArray.push_back(std::make_pair(first, first));
	}
    return splitArray;
}

void PmergeMe::sortEachPair(std::vector<std::pair<int, int> >& pairs)
{
    for (size_t i = 0; i < pairs.size(); ++i)
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
}

void printPairs(std::vector<std::pair<int, int> > pairs)
{
	for (std::vector<std::pair<int, int> >::iterator itr = pairs.begin(); itr != pairs.end(); itr++)
		std::cout << '(' << itr->first << ' ' << itr->second << ')' << std::endl;
}

template <typename Container>
void PmergeMe::insert(Container &container, std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size(); ++i)
	{        
		//std::cout << "Inserting smaller element: " << pairs[i].first << std::endl;

		typename Container::iterator it = std::lower_bound(container.begin(), container.end(), pairs[i].first);
		if (it == container.end() || *it != pairs[i].first)
			container.insert(it, pairs[i].first);

		//std::cout << "Array after insertion: " << std::endl;
		//for (typename Container::iterator it = container.begin(); it != container.end(); ++it)
		//	std::cout << *it << " ";
        //std::cout << std::endl;
	}
}

template <typename Container>
void PmergeMe::merge(Container &container, std::vector<int> larger_elements)
{
    container.clear();
    for (size_t i = 0; i < larger_elements.size(); ++i)
		container.push_back(larger_elements[i]);

	//std::cout << "Merged larger elements: " << std::endl;
	//for (typename Container::iterator it = container.begin(); it != container.end(); ++it)
	//	std::cout << *it << " ";
    //std::cout << std::endl;
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container &container)
{
    if (container.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs = create_pairs(container);

    //std::cout << "Pairs created: " << std::endl;
	//printPairs(pairs);

    sortEachPair(pairs);

    //std::cout << "Pairs sorted: " << std::endl;
	//printPairs(pairs);

    std::vector<int> larger_elements;
    for (size_t i = 0; i < pairs.size(); ++i)
		larger_elements.push_back(pairs[i].second);

	//std::cout << "Larger elements to sort recursively: " << std::endl;
    //for (size_t i = 0; i < larger_elements.size(); ++i)
	//	std::cout << larger_elements[i] << " ";
	//std::cout << std::endl;

	PmergeMe::mergeInsertSort(larger_elements);

	//std::cout << "Larger elements sorted: " << std::endl;
    //for (size_t i = 0; i < larger_elements.size(); ++i)
    //    std::cout << larger_elements[i] << " ";
    //std::cout << std::endl;

	PmergeMe::merge(container, larger_elements);
	PmergeMe::insert(container, pairs);
}
