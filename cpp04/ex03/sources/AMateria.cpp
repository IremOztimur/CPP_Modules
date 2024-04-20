/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:39:41 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/04/20 11:06:55 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(): type("Default") {
	std::cout << GRAY << "AMateria default constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;}

AMateria::AMateria(std::string const & type): type(type) {

	std::cout << GREEN << "AMateria constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "AMateria destructor called" << DEFAULT << std::endl;
}

AMateria::AMateria(AMateria const & other){
	std::cout << MAGENTA << "AMateria copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	*this=other;}

std::string const & AMateria::getType() const{
	return type;
}

void AMateria::use(ICharacter& target){
	(void)target;
	std::cout << "Using " << type << " on " << target.getName() << std::endl;
}
