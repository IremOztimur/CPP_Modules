/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:43:34 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/08 17:17:10 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base*	generate( void ) {
	if ( std::rand() % 3 == 0 )
		return ( new A );
	else if ( std::rand() % 3 == 1 )
		return ( new B );
	else
		return ( new C );
}

void	identify( Base* p ) {
	if ( dynamic_cast< A* >( p ) )
		std::cout << "A" << std::endl;
	else if ( dynamic_cast< B* >( p ) )
		std::cout << "B" << std::endl;
	else if ( dynamic_cast< C* >( p ) )
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

void	identify( Base& p ) {
	try {
		A& a = dynamic_cast< A& >( p );
		std::cout << "A" << std::endl;
		(void)a;
	} catch(const std::exception& e) {}
	try {
		B& b = dynamic_cast< B& >( p );
		std::cout << "B" << std::endl;
		(void)b;
	} catch( const std::exception& e ) {}
	try {
		C& c = dynamic_cast< C& >( p );
		std::cout << "C" << std::endl;
		(void)c;
	} catch( const std::exception& e ) {}
}

int		main( void )
{
	Base*	bp1 = generate();
	Base*	bp2 = generate();
	Base*	bp3 = generate();
	Base*	bp4 = generate();

	std::cout << std::endl;
	std::cout << MAGENTA << "--------------[bp 1]----------------" << RESET << std::endl;
	std::cout << std::endl;

    std::cout << "bp1* = "; identify( bp1 );
    std::cout << "bp1& = "; identify( *bp1 ); std::cout << std::endl;

	std::cout << MAGENTA << "--------------[bp 2]----------------" << RESET << std::endl;
	std::cout << std::endl;

    std::cout << "bp2* = "; identify( bp2 );
    std::cout << "bp2& = "; identify( *bp2 ); std::cout << std::endl;

	std::cout << MAGENTA << "--------------[bp 3]----------------" << RESET << std::endl;
	std::cout << std::endl;

    std::cout << "bp3* = "; identify( bp3 );
    std::cout << "bp3& = "; identify( *bp3 ); std::cout << std::endl;

	std::cout << MAGENTA << "--------------[bp 4]----------------" << RESET << std::endl;
	std::cout << std::endl;

    std::cout << "bp4* = "; identify( bp4 );
    std::cout << "bp4& = "; identify( *bp4 ); std::cout << std::endl;

	std::cout << MAGENTA << "------------------------------" << RESET << std::endl;
	std::cout << std::endl;


	delete bp1;
	delete bp2;
	delete bp3;
	delete bp4;

	return (0);
}
