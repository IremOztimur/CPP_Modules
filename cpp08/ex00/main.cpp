/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:36:11 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/12 16:39:31 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	try {
		// Test with vector
		std::vector<int> vec;

		for (int i = 0; i < 5; i++)
			vec.push_back(i);

		int valueToFindVec = 3;
		std::cout << std::endl;
		std::cout << MAGENTA << "-------[Vector Test]------"<< RESET << std::endl;
		std::cout << "Found value in vector: " << easyfind(vec, valueToFindVec) << std::endl;
		std::cout << std::endl;

		// Test with list
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        int valueToFindList = 40;
		std::cout << GREEN << "--------[List Test]-------"<< RESET << std::endl;
        std::cout << "Found value in list: " << easyfind(lst, valueToFindList) << std::endl;
		std::cout << std::endl;

		// Test with set
        std::set<int> mySet;
        mySet.insert(100);
        mySet.insert(200);
        mySet.insert(300);
        mySet.insert(400);
        mySet.insert(500);

        int valueToFindSet = 200;
		std::cout << YELLOW << "--------[Set Test]-------"<< RESET << std::endl;
        std::cout << "Found value in set: " << easyfind(mySet, valueToFindSet) << std::endl;
		std::cout << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
