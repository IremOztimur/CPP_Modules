/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:46:55 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/10 16:30:08 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(): type("Living Creature"){
	std::cout << GREEN << "Animal constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

Animal::~Animal(){
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "Animal destructor called" << DEFAULT << std::endl;
}

Animal::Animal(Animal const &other){
	std::cout << GREEN << "Animal copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	*this = other;
}

Animal &Animal::operator=(Animal const &rhs){
	std::cout << GREEN << "Animal assignation operator called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string Animal::getType() const{
	return (this->type);
}
