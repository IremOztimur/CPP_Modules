/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:15:15 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/12/10 17:43:03 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"

int main()
{
	{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << meta->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << "-----------------------------" << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();

	delete meta;
	delete j;
	}

	{
		const WrongAnimal *wrong = new WrongAnimal();
		const WrongAnimal *wrong_cat = new WrongCat();

		std::cout << wrong->getType() << std::endl;
		std::cout << wrong_cat->getType() << std::endl;
		std::cout << "-----------------------------" << std::endl;

		wrong->makeSound();
		wrong_cat->makeSound();

		delete wrong;
		delete wrong_cat;

	}
}
