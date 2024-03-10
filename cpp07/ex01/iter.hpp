/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:30:28 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/10 19:08:30 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <random>


#define RESET "\033[0m"
# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define GRAY "\x1b[37m"
# define GREEN "\x1b[32m"
# define CYAN "\x1b[36m"

const char* colorMacros[] = {RED, YELLOW, MAGENTA, GRAY, GREEN, CYAN};
const std::size_t numColors = sizeof(colorMacros) / sizeof(colorMacros[0]);


template <typename T, typename Func>
void	iter(T* array, size_t length, Func function) {
	for (size_t i = 0; i < length; ++i)
		function(array[i]);
}

template <typename T>
void printElement(const T &element) {
	std::cout << element << " ";
}

template <typename T>
void toLower(T &element) {
	if (!std::isdigit(element)) {
		element = std::tolower(element);
	}
}

const char* getRandomColor() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<std::size_t> distribution(0, numColors - 1);
	return colorMacros[distribution(gen)];
}
template <typename T>
void rainbow(T &element){
	const char *color = getRandomColor();
	std::cout << color << element << RESET << std::endl;
}

#endif
