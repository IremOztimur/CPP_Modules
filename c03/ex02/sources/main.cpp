/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:33:34 by ioztimur          #+#    #+#             */
/*   Updated: 2023/12/05 17:34:52 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"


int main()
{
	FragTrap highFiveGuy("Barney Stinson");

	highFiveGuy.attack("some random dude");
	highFiveGuy.highFivesGuys();
	highFiveGuy.takeDamage(99);
	highFiveGuy.beRepaired(10);
	highFiveGuy.takeDamage(100);
	highFiveGuy.highFivesGuys();
	return (0);
}
