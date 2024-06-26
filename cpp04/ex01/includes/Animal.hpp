/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:47:00 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/04/20 15:21:04 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

# define DEFAULT "\x1b[0m"
# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define GRAY "\x1b[37m"
# define GREEN "\x1b[32m"
# define CYAN "\x1b[36m"

class Animal
{
protected:
	std::string type;
public:
	Animal();
	virtual ~Animal();
	Animal(Animal const &other);
	Animal &operator=(Animal const &rhs);
	std::string	getType() const;

	virtual void makeSound() const;

};

#endif
