/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:30:18 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/11/23 15:35:10 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include <iostream>
//to do
// instruction panel
// a function to get input
// direct to input to functions

void	welcome(void)
{
	std::cout << "Welcome to your not ordinary Phone Book" << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "The commands you can use:" << std::endl;
	std::cout << "ADD	- to save a new contact" << std::endl;
	std::cout << "SEARCH	- to display a specific contact" << std::endl;
	std::cout << "EXIT	- to quit a program" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << std::endl;

}

int	main()
{
	PhoneBook	book;
	std::string	input = "";

	welcome();
	while (input.compare("EXIT")){
		if (input.compare("ADD") == 0)
		{
			book.addContact();
			std::cout << "> " << std::flush;
			std::cin >> input;
		}
		if (input.compare("SEARCH") == 0){
			book.printContacts();
			book.searchContact();
		}
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
	return (0);
}
