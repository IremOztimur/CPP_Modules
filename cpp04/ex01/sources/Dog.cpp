/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:32:45 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/10 16:20:39 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(): Animal(){
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << GREEN << "Dog constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

Dog::~Dog(){
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "Dog destructor called" << DEFAULT << std::endl;
	delete this->brain;
}

Dog::Dog(Dog const &other){
	std::cout << YELLOW << "Dog copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	*this = other;
}

Dog &Dog::operator=(Dog const &rhs){
	std::cout << GRAY << "Dog assignation operator called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Woffff Woffff" << std::endl;
}

void	Dog::setIdea(size_t index, std::string idea){
	this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(size_t index) const{
	return (this->brain->getIdea(index));
}
