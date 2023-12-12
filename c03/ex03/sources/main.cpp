/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:02:43 by ioztimur          #+#    #+#             */
/*   Updated: 2023/12/05 17:11:18 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main()
{
	DiamondTrap diamondTrap("IREM");
	diamondTrap.attack("target");
	diamondTrap.whoAmI();
	return (0);
}
