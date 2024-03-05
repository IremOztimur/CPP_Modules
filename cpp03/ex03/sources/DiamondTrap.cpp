/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:02:21 by ioztimur          #+#    #+#             */
/*   Updated: 2023/12/05 17:10:34 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << GREEN << "DiamondTrap constructor called" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap("Default")
{
	this->name = "Default";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << GREEN << "DiamondTrap default constructor called" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "---------------------------------------" << std::endl;
	std::cout << RED << "DiamondTrap destructor called" << DEFAULT << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	std::cout << YELLOW << "DiamondTrap copy constructor called" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << CYAN << "DiamondTrap assignation operator called" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
	}
	return (*this);
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}
