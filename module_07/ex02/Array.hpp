/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marde-vr <marde-vr@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:22:18 by marde-vr          #+#    #+#             */
/*   Updated: 2024/06/21 13:06:05 by marde-vr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <typename T> class Array
{
	private:
		T* ptr;
		size_t length;

	public:
		Array();
		Array(unsigned int n);
		Array(Array& cp);
		Array& operator=(Array& other);
		~Array();
		unsigned int size() const;
		T& operator[](unsigned int n);
};

template <typename T> Array<T>::Array(unsigned int n): ptr(new T[n]()), length(n) {}

template <typename T> Array<T>::Array(Array& cp)
{
	length = cp.size();
	ptr = new T[length];
	for (size_t i = 0; i < length; i++)
		ptr[i] = cp.ptr[i];
}

template <typename T> Array<T>& Array<T>::operator=(Array& other)
{
	length = other.size();
	if (ptr)
		delete[] ptr;
	ptr = new T[length];
	for (size_t i = 0; i < length; i++)
		ptr[i] = other.ptr[i];
}

template <typename T> Array<T>::~Array<T>()
{
	if (ptr)
		delete[] ptr;
}

template <typename T> T& Array<T>::operator[](unsigned int n)
{
	if (length <= n)
		throw std::out_of_range("Index is out of bounds");
	else
		return ptr[n];
}

template <typename T> unsigned int Array<T>::size() const
{
	return length;
}

#endif
