/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:22:53 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/11/23 16:12:30 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"phoneBook.hpp"

PhoneBook::PhoneBook(){};

void	PhoneBook::addContact(void)
{
	static int i;
	this->contacts[i % 8].init();
	this->contacts[i % 8].setIndex(i % 8);
	i++;
}

int		PhoneBook::readInput(void) const{
	int	input = -1;

	while (1)
	{
		std::cout << "Enter contact index please: " << std::flush;
		std::cin >> input;
		if ((input >= 0 && input <= 8) && std::cin.good())
			break;
		else{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Index; index range is 0-8" << std::endl;
		}
	}
	return (input);
}

void	PhoneBook::printContacts(void){
	std::cout << "---------PHONEBOOK CONTACTS---------" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
		this->contacts[i].view(i);
	std::cout << std::endl;
}

void	PhoneBook::searchContact(void){
	int	i  = this->readInput();
	this->contacts[i].display(i);
}
