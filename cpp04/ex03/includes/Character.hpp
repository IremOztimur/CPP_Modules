/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:46:07 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/04/20 13:03:53 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"

#ifndef INVENTORY_SIZE
	#define INVENTORY_SIZE 4
#endif

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[INVENTORY_SIZE];
	public:
		Character();
		Character(std::string const & name);
		~Character();
		Character(Character const & other);
		Character & operator=(Character const & rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

