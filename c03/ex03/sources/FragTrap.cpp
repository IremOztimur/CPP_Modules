/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:56:04 by ioztimur          #+#    #+#             */
/*   Updated: 2023/12/05 17:08:29 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN << "FragTrap constructor called" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap() : ClapTrap("Default")
{
	std::cout << GREEN << "FragTrap Constructor for " << name << " called!" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "---------------------------------------" << std::endl;
	std::cout << RED << "FragTrap destructor called" << DEFAULT << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << YELLOW << "FragTrap copy constructor called" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << CYAN << "FragTrap assignation operator called" << DEFAULT << std::endl;
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

void FragTrap::highFivesGuys(void)
{
	std::cout << CYAN << "FragTrap " << this->name << ": You want a high five???\n\t\t\t----- HANDS UP -----" << DEFAULT << std::endl;
}
