/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:53:47 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/11/23 16:11:02 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"


//Doesn't work properly
std::string Contact::getInput(std::string prompt) const
{
	std::string	input = "";

	while (1)
	{
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);

		if (std::cin.good() && !input.empty())
			break;
		else{
			std::cin.clear();
			std::cout << "Invalid input, please try again " << std::endl;
		}
	}
	return (input);
}

void Contact::init(void)
{
	std::cin.ignore();
	this->firstName = this->getInput("First Name: ");
	this->lastName = this->getInput("Last Name: ");
	this->nickname = this->getInput("Nickname: ");
	this->nickname = this->getInput("Phone Number: ");
	this->darkestSecret = this->getInput("Your Darkest Secret (it'll stay between us): ");
	std::cout << "\033[2J\033[H"; // to clear the terminal

}

void	Contact::setIndex(int	index){
	this->index = index;
}

std::string	Contact::formatLen(std::string str) const{
	if (str.size() > 10)
		return str.substr(0, 9) + '.';
	return str;
}

void	Contact::view(int	i){
	std::cout << "|" << std::setw(10) << "#" << i << std::flush;
	std::cout << "|" << std::setw(10) << this->formatLen(this->firstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->formatLen(this->lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->formatLen(this->nickname) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::display(int i) const{
	std::cout << std::endl;
	std::cout << "Contact #" << i << std::endl;
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
}
