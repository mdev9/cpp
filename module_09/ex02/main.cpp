/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:12:59 by marde-vr          #+#    #+#             */
/*   Updated: 2024/07/05 17:56:16 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
    if (argc < 2)
        return 0;

    std::vector<int> input;
    for (int i = 1; i < argc; ++i)
	{
        int number;
        std::istringstream iss(argv[i]);
        if (!(iss >> number) || number < 0)
		{
            std::cerr << "Error: Invalid input" << std::endl;
            return 1;
        }
        input.push_back(number);
    }

    PmergeMe sorter(input);
    sorter.displayBefore();
    sorter.sort();
    sorter.displayAfter();
	sorter.displayTimes();
    return 0;
}
