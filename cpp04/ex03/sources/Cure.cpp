/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:05:20 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/04/20 15:00:43 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure(): AMateria("cure") {
	std::cout << GRAY << "Cure default constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

Cure::~Cure() {
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "Cure destructor called" << DEFAULT << std::endl;
}

Cure::Cure(Cure const & other){
	std::cout << MAGENTA << "Cure copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	*this=other;}


Cure & Cure::operator=(Cure const & rhs){
	std::cout << YELLOW << "Cure '=' operator overloaded" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	(void)rhs;
	return *this;}

AMateria* Cure::clone() const{
	return new Cure(*this);
}

void Cure::use(ICharacter& target){
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << DEFAULT << std::endl;
}
