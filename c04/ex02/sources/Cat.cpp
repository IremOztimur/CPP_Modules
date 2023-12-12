/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:45:41 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/10 16:20:13 by ioztimur         ###   ########.fr       */
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
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

void	Cat::makeSound() const{
	std::cout << "Meow Meow" << std::endl;
}

void	Cat::setIdea(size_t index, std::string idea){
	this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(size_t index) const{
	return (this->brain->getIdea(index));
}
