/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:01:46 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/09 18:02:55 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal";
	std::cout << GREEN << "Wrong Animal constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "Wrong Animal destructor called" << DEFAULT << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other){
	std::cout << YELLOW << "Wrong Animal copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs){
	std::cout << GRAY << "Wrong Animal assignation operator called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void WrongAnimal::makeSound() const{
	std::cout << "Wrong Animal sound" << std::endl;
}

std::string WrongAnimal::getType() const{
	return (this->type);
}
