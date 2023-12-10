/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:32:45 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/09 17:49:47 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(): Animal(){
	this->type = "Dog";
	std::cout << GREEN << "Dog constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

Dog::~Dog(){
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "Dog destructor called" << DEFAULT << std::endl;
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
		this->type = rhs.type;
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Woffff Woffff" << std::endl;
}
