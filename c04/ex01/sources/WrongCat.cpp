/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:02:56 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/09 18:03:39 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	this->type = "WrongCat";
	std::cout << GREEN << "Wrong Cat constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "Wrong Cat destructor called" << DEFAULT << std::endl;
}

WrongCat::WrongCat(WrongCat const &other){
	std::cout << YELLOW << "Wrong Cat copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs){
	std::cout << GRAY << "Wrong Cat assignation operator called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void WrongCat::makeSound() const{
	std::cout << "OING OING" << std::endl;
}
