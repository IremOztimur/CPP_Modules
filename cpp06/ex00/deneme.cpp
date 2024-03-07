/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:55:19 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/07 14:58:32 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string deneme = "42.0ff";

	std::cout << std::count(deneme.begin(),deneme.end(), 'f') <<std::endl;
}
