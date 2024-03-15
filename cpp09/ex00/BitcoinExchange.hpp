/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:13:32 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/15 12:32:03 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

#define RESET "\033[39m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class BitcoinExchange{
	public:
		BitcoinExchange(const std::string &filename);
		~BitcoinExchange(){}
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void processInput(const std::string &input);
	private:
		std::map<std::string, double> data;
		BitcoinExchange();
		bool ValidateDate(const std::string &date);
		bool ValidateValue(const double &value);
		double	getExchangeRate(const std::string &date);
};

#endif
