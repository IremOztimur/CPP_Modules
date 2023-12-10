/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:45:41 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/09 23:56:33 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << GREEN << "Cat constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

Cat::~Cat()
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "Cat destructor called" << DEFAULT << std::endl;
	delete this->brain;
}


Cat::Cat(Cat const &other)
{
	std::cout << GREEN << "Cat copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	*this = other;
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << GREEN << "Cat assignation operator called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = rhs.brain;
	}
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << "Meow Meow" << std::endl;
}

