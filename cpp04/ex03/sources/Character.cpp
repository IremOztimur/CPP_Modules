/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:03:36 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/04/20 15:00:50 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(): name("Default"){
	std::cout << GRAY << "Character default constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = NULL;
}

Character::Character(std::string const & name): name(name)
{
	std::cout << GREEN << "Character constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = NULL;
}

Character::~Character() {
	std::cout << "-----------------------------" << std::endl;
	std::cout << RED << "Character destructor called" << DEFAULT << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

Character::Character(Character const & other): name(other.getName() + "_copy"){
	std::cout << MAGENTA << "Character copy constructor called" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	}
}

Character &	Character::operator=( Character const & src)
{
	std::cout << YELLOW << "Character '=' operator overloaded" << DEFAULT << std::endl;
	std::cout << "-----------------------------" << std::endl;
	if (this != & src)
	{
		for (size_t i = 0; i < INVENTORY_SIZE; i++)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
			inventory[i] = src.inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const{
	return name;
}

void Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
	{
		std::cout << this->name << " tried to equip nothing and it did nothing\n";
		return ;
	}
	while ((this->inventory)[i] != 0 && i < 4)
		i++;

	if (i >= 4)
	{
		std::cout << RED << this->name << " can't equip more than 4 Materia" << DEFAULT << std::endl;
		return ;
	}
	(this->inventory)[i] = m;
	std::cout << YELLOW << this->name << " equipped materia " << m->getType() << " in slot " << i << DEFAULT << "\n";
}

void Character::unequip(int idx){
	if (idx < 0 || idx >= INVENTORY_SIZE || !inventory[idx])
		return;
	else
	{
		AMateria *tmp = inventory[idx];
		std::cout << this->name << " unequipped " << tmp->getType() << " at slot "<< idx << "\n";
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || !(this->inventory)[idx])
		return;
	else
		inventory[idx]->use(target);
}
