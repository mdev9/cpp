/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:25:26 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/05 10:24:03 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

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
    mergeInsertSortVector(sorted_vector);
    clock_t end = clock();
    vectorTime = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    //mergeInsertSortList(sorted_list);
    end = clock();
    listTime = double(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::displayBefore() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < original.size(); ++i)
        std::cout << original[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
    std::cout << "After: ";
    for (size_t i = 0; i < sorted_vector.size(); ++i)
        std::cout << sorted_vector[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::displayTimes() const
{
    std::cout << "Time to process a range of " << original.size() << " elements with std::vector: " << vectorTime << " seconds\n";
    std::cout << "Time to process a range of " << original.size() << " elements with std::list: " << listTime << " seconds\n";
}

std::vector<std::pair<int, int> > create_pairs(const std::vector<int>& a)
{
    std::vector<std::pair<int, int> > split_array;
    for (size_t i = 0; i < a.size(); i += 2)
	{
        if (i + 1 < a.size())
            split_array.push_back(std::make_pair(a[i], a[i + 1]));
        else
            split_array.push_back(std::make_pair(a[i], a[i]));
    }
    return split_array;
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

void PmergeMe::insert(std::vector<int> &vector, std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size(); ++i)
	{        
		//std::cout << "Inserting smaller element: " << pairs[i].first << std::endl;

		size_t left = 0;
		size_t right = vector.size();
		while (left < right) {
			size_t mid = (left + right) / 2;
			if (pairs[i].first < vector[mid])
				right = mid;
			else
				left = mid + 1;
		}
		vector.insert(vector.begin() + left, pairs[i].first);

		//std::cout << "Array after insertion: " << std::endl;
        //for (size_t j = 0; j < vector.size(); ++j)
        //    std::cout << vector[j] << " ";
        //std::cout << std::endl;
	}
}

void PmergeMe::merge(std::vector<int> &vector, std::vector<int> larger_elements)
{
    vector.clear();
    for (size_t i = 0; i < larger_elements.size(); ++i)
		vector.push_back(larger_elements[i]);

	//std::cout << "Merged larger elements: " << std::endl;
    //for (size_t i = 0; i < vector.size(); ++i)
    //   std::cout << vector[i] << " ";
    //std::cout << std::endl;
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &vector)
{
    if (vector.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs = create_pairs(vector);

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

	PmergeMe::mergeInsertSortVector(larger_elements);

	//std::cout << "Larger elements sorted: " << std::endl;
    //for (size_t i = 0; i < larger_elements.size(); ++i)
    //    std::cout << larger_elements[i] << " ";
    //std::cout << std::endl;

	PmergeMe::merge(vector, larger_elements);
	PmergeMe::insert(vector, pairs);
}
