/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:04:15 by ioztimur          #+#    #+#             */
/*   Updated: 2023/12/05 13:44:24 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): hitPoints(10), energyPoints(10), attackDamage(0), name(name){
	std::cout << GREEN << "ClapTrap default constructor called" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

ClapTrap::ClapTrap(): hitPoints(10), energyPoints(10), attackDamage(0), name("Default"){
	std::cout << GREEN << "ClapTrap default constructor called" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "---------------------------------------" << std::endl;
	std::cout << RED << "ClapTrap destructor called" << DEFAULT << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << YELLOW << "ClapTrap copy constructor called" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy){
	std::cout << CYAN << "ClapTrap assignation operator called" << DEFAULT << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	if (this != &copy)
	{
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
		this->name = copy.name;
	}
	return (*this);
}

void ClapTrap::attack(std::string const &target){
	if (this->energyPoints <= 0)
	{
		std::cout << GRAY << "ClapTrap " << this->name << " has no energy points" << DEFAULT << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << GRAY << "ClapTrap " << this->name << " is dead (a death can't attack)" << DEFAULT << std::endl;
		return ;
	}
	std::cout << MAGENTA << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << DEFAULT << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hitPoints <= amount)
	{
		this->hitPoints = 0;
		std::cout << GRAY << "ClapTrap " << this->name << " is dead" << DEFAULT << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	std::cout << RED << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << DEFAULT << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->energyPoints <= 0)
	{
		std::cout << GRAY << "ClapTrap " << this->name << " has no energy points" << DEFAULT << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << GRAY << "ClapTrap " << this->name << " is dead (a death can't attack)" << DEFAULT << std::endl;
		return ;
	}
	std::cout << YELLOW << "ClapTrap " << this->name << " has been repaired for " << amount << " hit points!" << DEFAULT << std::endl;
	this->energyPoints--;
	hitPoints += amount;
}
