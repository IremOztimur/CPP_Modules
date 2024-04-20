/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:58:25 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/04/20 15:01:12 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice(): AMateria("ice") {
	std::cout << GRAY << "Ice default constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;}

Ice::~Ice() {
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "Ice destructor called" << DEFAULT << std::endl;
}

Ice::Ice(Ice const & other){
	std::cout << MAGENTA << "Ice copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	*this=other;}

Ice & Ice::operator=(Ice const & rhs){
	std::cout << YELLOW << "Ice '=' operator overloaded" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	(void)rhs;
	return *this;}

AMateria* Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter& target){
	std::cout << CYAN << "* shoots an ice bolt at " << target.getName() << " *" << DEFAULT << std::endl;
}
