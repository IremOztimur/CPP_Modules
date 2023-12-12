/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:33:34 by ioztimur          #+#    #+#             */
/*   Updated: 2023/12/05 12:28:45 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main()
{
	{
		ClapTrap clap("irem");
		int i = 0;
		// Test to run out of mana
		clap.takeDamage(5);
		clap.beRepaired(20);

		// Test to run out of health
		while (i < 11)
		{
			clap.attack("enemy");
			if (i == 4)
				clap.takeDamage(40);
			i++;
		}
	}
	std::cout << "---------------------------------------" << std::endl;
	{
		ClapTrap clap("irem");
		int i = 0;

		clap.attack("enemy");

		clap.takeDamage(8);
		while (i < 11)
		{
			clap.attack("enemy");
			i++;
		}
	}
	return (0);
}
