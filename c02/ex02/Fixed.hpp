/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:54:09 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/03 18:33:28 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

# define DEFAULT "\x1b[0m"
# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define GRAY "\x1b[37m"
# define GREEN "\x1b[32m"
# define CYAN "\x1b[36m"


class Fixed
{
private:
	int	fixedPointValue;
	static const int	fractional_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &copy_object);
	Fixed(const int n);
	Fixed(const float n);

	~Fixed();

	Fixed &operator=(const Fixed &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float	toFloat(void)const;
	int		toInt(void)const;

	//Comparison operators
	bool	operator<(const Fixed &rhs) const;
	bool	operator>(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	// Arithmetic operators
	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;


	Fixed&	operator++( void ); // prefix
	Fixed	operator++( int ); // postfix
	Fixed&	operator--( void ); // prefix
	Fixed	operator--( int ); // postfix

	// Member functions
	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed& max( Fixed &a, Fixed &b );
	static const Fixed& max( const Fixed &a, const Fixed &b );

};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif
