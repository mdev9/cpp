/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:24:54 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/05 09:43:36 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const std::vector<int> &input);
		PmergeMe(PmergeMe& cp);
		PmergeMe& operator=(PmergeMe& other);
		~PmergeMe();

		void sort();
		void displayBefore() const;
		void displayAfter() const;
		void displayTimes() const;

	private:
		std::vector<int> original;
		std::vector<int> sorted_vector;
		std::list<int> sorted_list;

		double vectorTime;
		double listTime;

		void sortEachPair(std::vector<std::pair<int, int> >& pairs);
		void mergeInsertSortVector(std::vector<int> &vector);
		void merge(std::vector<int> &vector, std::vector<int> larger_elements);
		void insert(std::vector<int> &vector, std::vector<std::pair<int, int> > &pairs);
		void mergeInsertSortList(std::list<int> &list);
};

#endif
