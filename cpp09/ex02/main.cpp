/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 09:34:56 by ioztimur          #+#    #+#             */
/*   Updated: 2024/03/16 11:04:40 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **av)
{
	if (argc < 2)
	{
		std::cout << RED << "Usage: ./PmergeMe [0-9]+" << RESET << std::endl;
		return (EXIT_FAILURE);
	}

	std::list<int> list;
	std::deque<int> deque;

	if (!ValidateAndParse(argc, av, list, deque))
	{
		std::cout << RED << "Usage: ./PmergeMe [0-9]+" << RESET << std::endl;
		return (EXIT_FAILURE);
	}

	std::cout << MAGENTA << "---------------------------------" << RESET << std::endl;
	std::cout << "List Before Sorting: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::clock_t start_time = std::clock();
	MergeInsertSort(list);
	std::clock_t end_time = std::clock();

	std::cout << "List After Sorting: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	double sort_time = static_cast<double>(end_time - start_time) / (double)CLOCKS_PER_SEC* 1000000;
	std::cout << "Time to process a range of " << list.size() << " elements: " << sort_time << " us" << std::endl;
	std::cout << MAGENTA << "---------------------------------" << RESET << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "---------------------------------" << RESET << std::endl;
	std::cout << "Deque Before Sorting: ";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	start_time = std::clock();
	MergeInsertSort(deque);
	end_time = std::clock();

	std::cout << "Deque After Sorting: ";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	sort_time = static_cast<double>(end_time - start_time) / (double)CLOCKS_PER_SEC* 1000000;
	std::cout << "Time to process a range of " << deque.size() << " elements: " << sort_time << " us" << std::endl;
	std::cout << YELLOW << "---------------------------------" << RESET << std::endl;

	return (0);
}
