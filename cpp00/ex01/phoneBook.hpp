/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 00:12:24 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/11/23 12:21:38 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "contact.hpp"

#define	MAX_CONTACTS		8
#define	MAX_CONTACT_INDEX	7

class	PhoneBook
{
	private:
		Contact	contacts[MAX_CONTACTS];

		int		readInput(void) const;
	public:
		PhoneBook();

		void	addContact(void);
		void	searchContact(void);
		void	printContacts(void);
};


#endif
