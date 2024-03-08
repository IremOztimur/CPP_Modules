/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:07:43 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/08 22:48:56 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int main( void )
{
{	std::cout << MAGENTA << "----------------[1 - Integer]----------------" << RESET << std::endl;
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << MAGENTA << "---------------[2 - String]----------------" << RESET << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << MAGENTA << "----------------[3 - Float]----------------" << RESET << std::endl;
		std::cout << std::endl;

		float x = 25.4;
		float y = 42.42f;

		::swap( x, y );
		std::cout << "x = " << x << ", y = " << y << std::endl;
		std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
		std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;
	}

	return (0);
}
