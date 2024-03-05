/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:38:40 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/01 08:57:30 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor
Fixed::Fixed(): fixedPointValue(0){
	std::cout << GREEN << "object has been initialized" << DEFAULT << std::endl;
}

// Destructor
Fixed::~Fixed(){
	std::cout << RED << "object has been destroyed" << DEFAULT << std::endl;
}

// Copy Constructor
Fixed::Fixed(const Fixed &copy_object): fixedPointValue(copy_object.fixedPointValue){
	std::cout << YELLOW << "object has been copied" << DEFAULT << std::endl;
}

// Copy Overload Operator
Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << GRAY << "Operator overloaded" << DEFAULT << std::endl;
	if (this != &rhs)
		this->fixedPointValue = rhs.getRawBits();

	return *this;
}

int	Fixed::getRawBits(void)const{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fixedPointValue);
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}
