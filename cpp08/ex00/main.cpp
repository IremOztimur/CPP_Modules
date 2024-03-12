/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:36:11 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/12 15:37:38 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	try {
		// Test with vector
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(3);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);

		int valueToFindVec = 2;
		std::cout << "Found value in vector: " << easyfind(vec, valueToFindVec) << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
