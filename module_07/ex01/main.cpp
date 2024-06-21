/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:00:28 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/21 10:20:07 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void printInt(int &x) {
    std::cout << x << " ";
}

void increment(int &x) {
    ++x;
}

template <typename T>
void printElement(T &element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = 5;

    iter(intArray, intArrayLength, printInt);
    std::cout << std::endl;
    iter(intArray, intArrayLength, increment);
    iter(intArray, intArrayLength, printInt);
    std::cout << std::endl;

    std::string strArr[] = {"Hello", "World", "!"};
    size_t strArrLen = 3;

    iter(strArr, strArrLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
