/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:50:15 by ioztimur          #+#    #+#             */
/*   Updated: 2024/03/11 17:40:34 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

#define RESET "\033[0m"
# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define GRAY "\x1b[37m"
# define GREEN "\x1b[32m"
# define CYAN "\x1b[36m"

template <class T>
class Array
{
	private:
		unsigned int n;
		T			*array;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array &operator=(const Array &other);
		T &operator[](unsigned int index);
		unsigned int size() const;

		class InvalidIndexException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <class T>
Array<T>::Array(): n(1)
{
	std::cout << GRAY << "Default constructor called" << RESET << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	this->array = new T[1];
	array[0] = 0;
}

template <class T>
Array<T>::Array(unsigned int n): n(n)
{
	std::cout << GREEN << "Parameterized constructor called " << RESET << std::endl;
	std::cout << GRAY << "- created an array of size "<< n << RESET << std::endl;
	this->array = new T[n];
	std::cout << "-------------------------------------" << std::endl;
}

template <class T>
Array<T>::~Array()
{
	std::cout << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << RED << "Destructor called" << RESET << std::endl;
	delete [] this->array;
}

template <class T>
Array<T>::Array(const Array &other)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	this->n = other.n;
	this->array = new T[other.n];
	for (unsigned int i = 0; i < other.n; i++)
		this->array[i] = other.array[i];
	std::cout << "-------------------------------------" << std::endl;
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other)
{
	std::cout << MAGENTA << "Assignation operator called" << RESET << std::endl;
	if (this == &other)
		return *this;
	delete [] this->array;
	this->n = other.n;
	this->array = new T[other.n];
	for (unsigned int i = 0; i < other.n; i++)
		this->array[i] = other.array[i];
	std::cout << "-------------------------------------" << std::endl;
	return *this;
}

template <class T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->n)
		throw(InvalidIndexException());
	//std::cout << CYAN << "Element at index " << index << " is " << this->array[index] << RESET << std::endl;
	return this->array[index];
}

template <class T>
unsigned int Array<T>::size() const{
	return this->n;
}

template <class T>
const char *Array<T>::InvalidIndexException::what() const throw()
{
	return "Index out of range";
}


#endif
