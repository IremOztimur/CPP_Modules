/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:11:34 by ioztimur          #+#    #+#             */
/*   Updated: 2024/03/16 11:08:56 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool ValidateAndParse(int argc, char **av, std::list<int> &list, std::deque<int> &deque){
	std::string 		token;
	std::stringstream	ss;


	for (int i = 1; i < argc; i++)
		ss << av[i] << " ";

	while (ss >> token){
		char *endptr = NULL;
		long number = std::strtol(token.c_str(), &endptr, 10);
		if (*endptr == '\0' && number >= 0 && number < INT_MAX){
			list.push_back(number);
			deque.push_back(number);
		}
		else
		{
			std::cout << "Invalid input: "<< token << std::endl;
			return (false);
		}
	}
	return (true);
}
