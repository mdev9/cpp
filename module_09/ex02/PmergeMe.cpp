/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:25:26 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/04 12:08:26 by marde-vr         ###   ########.fr       */
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

void PmergeMe::sort() {
    sorted_vector = original;
    sorted_list.assign(original.begin(), original.end());

    clock_t start = clock();
    mergeInsertSortVector(sorted_vector);
    clock_t end = clock();
    vectorTime = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    mergeInsertSortList(sorted_list);
    end = clock();
    listTime = double(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::displayBefore() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < original.size(); ++i) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const {
    std::cout << "After: ";
    for (size_t i = 0; i < sorted_vector.size(); ++i) {
        std::cout << sorted_vector[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayTimes() const {
    std::cout << "Time to process a range of " << original.size() << " elements with std::vector: " << vectorTime << " seconds\n";
    std::cout << "Time to process a range of " << original.size() << " elements with std::list: " << listTime << " seconds\n";
}

int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int> PmergeMe::buildJacobInsertionSequence(int length) {
    std::vector<int> sequence;
    int index = 3;
    while (jacobsthal(index) < length - 1) {
        sequence.push_back(jacobsthal(index));
        ++index;
    }
    return sequence;
}

std::vector<std::pair<int, int> > create_pairs(const std::vector<int>& a) {
    std::vector<std::pair<int, int> > split_array;
    for (size_t i = 0; i < a.size(); i += 2) {
        if (i + 1 < a.size()) {
            split_array.push_back(std::make_pair(a[i], a[i + 1]));
        } else {
            split_array.push_back(std::make_pair(a[i], a[i]));
        }
    }
    return split_array;
}

void sort_each_pair(std::vector<std::pair<int, int> >& pairs) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first > pairs[i].second) {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }
}

void insert(const std::pair<int, int>& element, std::vector<std::pair<int, int> >& A, int n) {
    if (n < 0) {
        A[0] = element;
    } else if (element.second >= A[n].second) {
        if (n == static_cast<int>(A.size()) - 1) {
            A.push_back(element);
        } else {
            A[n + 1] = element;
        }
    } else {
        if (n == static_cast<int>(A.size()) - 1) {
            A.push_back(A[n]);
        } else {
            A[n + 1] = A[n];
            insert(element, A, n - 1);
        }
    }
}

void insertion_sort_pairs(std::vector<std::pair<int, int> >& A, int n) {
    if (n < 1) return;
    insertion_sort_pairs(A, n - 1);
    insert(A[n], A, n - 1);
}

void sort_by_larger_value(std::vector<std::pair<int, int> >& pairs) {
    insertion_sort_pairs(pairs, pairs.size() - 1);
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
    bool hasStraggler = arr.size() % 2 != 0;
    int straggler = hasStraggler ? arr.back() : 0;
    if (hasStraggler) arr.pop_back();

    std::vector<std::pair<int, int> > pairs = create_pairs(arr);
    sort_each_pair(pairs);
    sort_by_larger_value(pairs);

    std::vector<int> S, pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        S.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
    S.insert(S.begin(), pend[0]);
    pend.erase(pend.begin());

    std::vector<int> jacob_insertion_sequence = buildJacobInsertionSequence(pend.size());

    size_t iterator = 0;
    while (iterator < pend.size()) {
        int item;
        if (iterator < jacob_insertion_sequence.size() && jacob_insertion_sequence[iterator] < static_cast<int>(pend.size())) {
            item = pend[jacob_insertion_sequence[iterator] - 1];
        } else {
            item = pend[iterator];
        }

        std::vector<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), item);
        if (insertion_point == S.end() || *insertion_point != item) {
            S.insert(insertion_point, item);
        }
        ++iterator;
    }

    if (hasStraggler) {
        std::vector<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), straggler);
        if (insertion_point == S.end() || *insertion_point != straggler) {
            S.insert(insertion_point, straggler);
        }
    }

    arr = S;
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr) {
    bool hasStraggler = arr.size() % 2 != 0;
    int straggler = hasStraggler ? arr.back() : 0;
    if (hasStraggler) arr.pop_back();

    std::vector<int> arr_vec(arr.begin(), arr.end());
    std::vector<std::pair<int, int> > pairs = create_pairs(arr_vec);
    sort_each_pair(pairs);
    sort_by_larger_value(pairs);

    std::list<int> S, pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        S.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }

    std::vector<int> jacob_insertion_sequence = buildJacobInsertionSequence(pend.size());

    size_t iterator = 0;
    while (iterator < pend.size()) {
        int item;
        if (iterator < jacob_insertion_sequence.size() && jacob_insertion_sequence[iterator] - 1 < static_cast<int>(pend.size())) {
            std::list<int>::iterator it = pend.begin();
            std::advance(it, jacob_insertion_sequence[iterator] - 1);
            item = *it;
        } else {
            item = *pend.begin();
        }

        std::list<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), item);
        S.insert(insertion_point, item);
        pend.pop_front();
        ++iterator;
    }

    if (hasStraggler) {
        std::list<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(insertion_point, straggler);
    }

    arr = S;
}
