/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:05:21 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/08 22:54:17 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

#define RED "\033[1;31m"
#define MAGENTA "\033[1;35m"
#define RESET "\033[0m"

template<typename T>
const T &max(const T &x, const T &y)
{
	return (x > y) ? x : y;
}


template <typename T>
const T &min(const T &x, const T &y)
{
	return (x < y) ? x : y;
}

template <typename T>
void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

#endif
