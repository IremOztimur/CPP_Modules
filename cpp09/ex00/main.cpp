/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:12:54 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/14 16:15:08 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **av)
{
	if (argc != 2)
	{
		std::cout << RED << "Error: could not open file." << RESET  << std::endl;
		std::cerr << GREY << "Usage: ./bitcoin [input_file]" << RESET << std::endl;
		return 1;
	}
	BitcoinExchange exchange("data.csv");
	exchange.processInput(av[1]);
	return 0;
}
