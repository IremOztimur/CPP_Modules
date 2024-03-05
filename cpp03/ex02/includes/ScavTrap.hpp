/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:28:55 by ioztimur          #+#    #+#             */
/*   Updated: 2023/12/05 13:44:11 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header Protection
#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool isGuardMode;
public:
	ScavTrap(std::string name);
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &copy);
	void guardGate(void);
};
