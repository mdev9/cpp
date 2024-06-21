/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:22:18 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/21 11:03:20 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <typename T> class Array
{
	private:
		T* ptr;
		size_t lenght;

	public:
		Array();
		Array(unsigned int n);
		Array(Array& cp);
		Array& operator=(Array& other);
		unsigned int size() const;
		T& operator[](unsigned int n);
};


template <typename T> Array<T>::Array(unsigned int n): ptr(new T[n]()), lenght(n) {}

template <typename T> Array<T>::Array(Array& cp)
{
	lenght = cp.size();
	ptr = new T[lenght];
	for (size_t i = 0; i < lenght; i++)
		ptr[i] = cp.ptr[i];
}

template <typename T> Array<T>& Array<T>::operator=(Array& other)
{
	lenght = other.size();
	//delete old ptr?
	ptr = new T[lenght];
	for (size_t i = 0; i < lenght; i++)
		ptr[i] = other.ptr[i];
}

template <typename T> T& Array<T>::operator[](unsigned int n)
{
	if (lenght < n)
		throw std::out_of_range("Index is out of bounds");
	else
		return ptr[n];
}

template <typename T> unsigned int Array<T>::size() const
{
	return lenght;
}


#endif
