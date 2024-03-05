/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:44:46 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/09 21:28:45 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	~Cat();
	Cat(Cat const &other);
	Cat &operator=(Cat const &rhs);

	void makeSound() const;
};
