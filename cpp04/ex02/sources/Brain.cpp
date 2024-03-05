/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:29:54 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/09 23:51:53 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "Brain constructor called" << DEFAULT << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
	std::cout << "-----------------------------" << std::endl;
}

Brain::~Brain()
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "Brain destructor called" << DEFAULT << std::endl;
}

Brain::Brain(Brain const &other)
{
	std::cout << YELLOW << "Brain copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << GRAY << "Brain assignation operator called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
				this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

void Brain::setIdea(size_t index, std::string idea){
	if (index < 0 || index > 99)
		return ;
	this->ideas[index] = idea;
}

std::string Brain::getIdea(size_t index) const{
	if (index < 0 || index > 99)
		return ("Invalid index");
	return (this->ideas[index]);
}
