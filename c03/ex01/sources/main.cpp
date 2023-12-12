/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:33:34 by ioztimur          #+#    #+#             */
/*   Updated: 2023/12/05 13:46:37 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"


int main()
{
	ScavTrap robot("robot");
	int i = 0;
	robot.attack("enemy");
	robot.takeDamage(95);
	robot.guardGate();
	while (i++ < 7)
	{
		robot.attack("enemy");
		if (i == 5)
		{
			robot.guardGate();
			robot.beRepaired(10);
			//to kill the robot increase the damage more or equal to 15
			robot.takeDamage(15);
		}
	}
	return (0);
}
