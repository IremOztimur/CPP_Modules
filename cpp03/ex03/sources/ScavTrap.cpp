/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:02:19 by ioztimur          #+#    #+#             */
/*   Updated: 2023/12/05 17:12:14 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->isGuardMode = false;
	std::cout << GREEN << "ScavTrap Constructor for " << name << " called!" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

ScavTrap::ScavTrap(): ClapTrap("Default")
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->isGuardMode = false;
	std::cout << GREEN << "ScavTrap Constructor for " << name << " called!" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "---------------------------------------" << std::endl;
	std::cout << RED << "ScavTrap Destructor called!" << DEFAULT << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << YELLOW << "ScavTrap Copy constructor called!" << DEFAULT << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << GRAY << "ScavTrap Assignation operator called!" << DEFAULT << std::endl;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
	}
	return (*this);
}

void ScavTrap::guardGate(){
	if (this->isGuardMode == false)
	{
		this->isGuardMode = true;
		std::cout << GREEN << "ScavTrap have enterred in Gate keeper mode!" << DEFAULT << std::endl;
	}
	else
		std::cout << GRAY << "ScavTrap is already in Gate keeper mode!" << DEFAULT << std::endl;
}
