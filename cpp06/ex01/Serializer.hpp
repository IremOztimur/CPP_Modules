/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:10:17 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/07 15:39:47 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>


// Color Codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"


typedef struct Data
{
	std::string name;
	int			age;
} Data;

class Serializer{
	public:
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif

/*
Notes:
uintptr_t is an unsigned integer type such that any valid (void *)
value can be converted to this type and then converted back.
It is capable of storing values in the range [0, INTPTR_MAX].
*/
