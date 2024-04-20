/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:50:05 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/04/20 15:13:57 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << GRAY << "MateriaSource default constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = 0;
}

MateriaSource::~MateriaSource() {
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "MateriaSource destructor called" << DEFAULT << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const & other) {
	std::cout << MAGENTA << "MateriaSource copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	std::cout << YELLOW << "MateriaSource '=' operator overloaded" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	if (this != &rhs)
	{
		for (size_t i = 0; i < INVENTORY_SIZE; i++)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
			inventory[i] = rhs.inventory[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	while (this->inventory[i] && i < INVENTORY_SIZE)
		i++;
	if (i == INVENTORY_SIZE)
	{
		std::cout << RED << "Inventory is full" << DEFAULT << std::endl;
		return ;
	}
	this->inventory[i] = m;
	std::cout << MAGENTA << "Materia learned " << m->getType() << DEFAULT << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
		{
			std::cout << GREEN << "Materia created " << type << DEFAULT << std::endl;
			return this->inventory[i]->clone();
		}
	}
	std::cout << RED << "Materia not found" << DEFAULT << std::endl;
	return 0;
}
