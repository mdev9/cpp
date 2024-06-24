/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:47:55 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/24 14:28:44 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(6);

    try {
        std::vector<int>::iterator it = easyfind(numbers, 3);
        std::cout << "Found " << *it << std::endl;
    } catch (const NoOccurenceFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(numbers, 7);
        std::cout << "Found: " << *it << std::endl;
    } catch (const NoOccurenceFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
