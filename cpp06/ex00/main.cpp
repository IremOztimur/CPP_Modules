/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:25:54 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/06 21:07:47 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **av)
{

	if (argc != 2)
	{
		std::cerr << RED << "Usage: ./convert [value]" << RESET << std::endl;
		return 1;
	}


	try {
		ScalarConverter sc(av[1]);
		sc.convert();
		std::cout << sc;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

}
