/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:23:33 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/04/20 15:20:32 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"


// int main() {
//     Ice ice;
//     Cure cure;

//     Character* character = new Character("Alice");

//     std::cout << "Ice type: " << ice.getType() << std::endl;
//     std::cout << "Cure type: " << cure.getType() << std::endl;

//     std::cout << "Character name: " << character->getName() << std::endl;

//     character->equip(&ice);
//     character->equip(&cure);
// 	character->equip(&ice);
// 	character->equip(&ice);
// 	character->equip(&ice);

//     character->unequip(0);

//     character->use(1, *character);
// 	character->use(2, *character);

//     return 0;

// }

int main() {

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob; delete me; delete src;
	return 0;
}
