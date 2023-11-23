/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:49:36 by iremoztimur       #+#    #+#             */
/*   Updated: 2023/11/23 13:26:04 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class	Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string	darkestSecret;
	int			index;

	std::string getInput(std::string prompt) const;
	std::string	formatLen(std::string str) const;
public:
	void		init(void);
	void		setIndex(int i);
	void		view(int	i);
	void		display(int	i) const;
};

#endif
