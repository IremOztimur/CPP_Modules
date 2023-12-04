/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:54:09 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/01 08:57:30 by iremoztimur      ###   ########.fr       */
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

class Fixed
{
private:
	int	fixedPointValue;
	static const int	fractional_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &copy_object);

	~Fixed();

	Fixed &operator=(const Fixed &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
