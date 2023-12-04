/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:53:09 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/03 19:41:11 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Constructor
Fixed::Fixed(): fixedPointValue(0){
	std::cout << GREEN << "object has been initialized" << DEFAULT << std::endl;
}

// Destructor
Fixed::~Fixed(){
	std::cout << RED << "object has been destroyed" << DEFAULT << std::endl;
}

// Constructor for integer
Fixed::Fixed(const int n): fixedPointValue(n << fractional_bits){
std::cout << MAGENTA << "int constuctor has been called" << DEFAULT << std::endl;
}

// Constructor for floating-point number
Fixed::Fixed(const float n){
	int	scaling_factor = 1 << fractional_bits;
	fixedPointValue = std::roundf(n * scaling_factor);
	std::cout << CYAN << "float constuctor has been called" << DEFAULT << std::endl;
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
	//std::cout << "getRawBits member function called" << std::endl;
	return(this->fixedPointValue);
}

void	Fixed::setRawBits(int const raw){
	//std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

int		Fixed::toInt(void)const{
	return (this->fixedPointValue >> fractional_bits);
}

float	Fixed::toFloat(void)const{
	return (static_cast<float>(this->getRawBits()) / (1 << fractional_bits));
}

// to print out the fixed object in its floating point representation
std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
	o << i.toFloat();
	return o;
}

//----------------- Comparison operators -----------------//

bool	Fixed::operator>(const Fixed &rhs)const{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs)const{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs)const{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs)const{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs)const{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs)const{
	return (this->getRawBits() != rhs.getRawBits());
}

//---------------- Arithmetic operators ----------------//

Fixed	Fixed::operator+(const Fixed &rhs) const{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const{
	return (this->toFloat() / rhs.toFloat());
}

//------------- Increment/Decrement operators --------------//

Fixed&	Fixed::operator++( void ){
	++this->fixedPointValue;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed	tmp(*this);
	tmp.fixedPointValue = this->fixedPointValue++;
	return tmp;
}

Fixed&	Fixed::operator--( void ){
	--this->fixedPointValue;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed	tmp(*this);
	tmp.fixedPointValue = this->fixedPointValue--;
	return tmp;
}

//-------------------- Max and Min -------------------//

Fixed	&Fixed::min(Fixed &a, Fixed &b){
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b){
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b){
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}
