/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:09:03 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/15 17:36:30 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::size_type delimiter_pos = line.find(',');

		if (delimiter_pos == std::string::npos)
		{
			std::cerr << RED << "Error: Invalid format in database => " << line << RESET << std::endl;
			continue;
		}

		std::string date = line.substr(0, delimiter_pos);
		std::string exchange_str = line.substr(delimiter_pos + 1);

		double exchange_rate;
		std::istringstream lineParser(exchange_str);

		if (!(lineParser >> exchange_rate)) {
			std::cerr << "Error: Invalid rate format in database => "
				  << exchange_str << '\n';
			continue;
		}

		this->data[date] = exchange_rate;
	}
}

// Checkers
bool BitcoinExchange::ValidateDate(const std::string &date){
	std::string::size_type del1 = date.find('-');
	std::string::size_type del2 = date.rfind('-');

	if (del1 == std::string::npos || del1 == del2)
		return false;

	std::string year_str = date.substr(0, del1);
	std::string month_str = date.substr(del1 + 1, del2 - del1 - 1);
	std::string day_str = date.substr(del2 + 1);

	// Check size
	if (year_str.size() != 4 || month_str.size() != 2 || day_str.size() != 2)
		return false;

	int year, month, day;
	std::istringstream year_ss(year_str), month_ss(month_str), day_ss(day_str);

	if (!(year_ss >> year) || !(month_ss >> month) || !(day_ss >> day))
		return false;

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	// Check for months with only 30 days
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return false;
	}

	// Check for February
	if (month == 2) {
		// Check for leap year
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
			return false;
		}
	}

	return true;
}

// A valid value must be either a float or a positive integer, between 0 and 1000.
bool BitcoinExchange::ValidateValue(const double &value){
	if (value < 0){
		std::cerr <<  RED << "Error: not a positive number | "<< RESET;
		return false;
	}
	else if (value > 1000){
		std::cerr <<  RED << "Error: value is too high | "<< RESET;
		return false;
	}
	else
		return true;
}

double	BitcoinExchange::getExchangeRate(const std::string &date){
	std::map<std::string, double>::iterator iter = this->data.lower_bound(date);

	if (iter->first != date && iter != this->data.begin())
		--iter;
	if (iter != this->data.end())
		return iter->second;
	else if (!data.empty())
		return iter->second;

	return -1.0;
}

void BitcoinExchange::processInput(const std::string &input)
{
	std::ifstream file(input.c_str());
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream lineParser(line);
		std::string date;
		double value;
		char delimiter;

		if (!(lineParser >> date >> delimiter >> value))
		{
			std::cerr << RED << "Error: Unable to parse line => " << RESET << line  << std::endl;
			continue;
		}

		if (delimiter != '|') {
			std::cerr << RED << "Error: Expected '|' delimiter in line => "
				<< RESET << line << std::endl;
			continue;
		}

		if (!ValidateDate(date)) {
			std::cerr <<  GREY << "Error: Invalid date format in line => "<< RESET <<
			line << std::endl;
			continue;
		}


		if (!ValidateValue(value)) {
			std::cerr <<  RED << "Invalid value in line => " << RESET << line << std::endl;
			continue;
		}

		double exchangeRate = getExchangeRate(date);

		if (exchangeRate == -1.0) {
			std::cerr << RED << "Error: No exchange rate available for date => "
			<< RESET << date << '\n';
			continue;
		}
		std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;

	}
}
