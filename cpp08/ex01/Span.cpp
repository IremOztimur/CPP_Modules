/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:07:38 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/03/12 21:56:40 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {
	std::cout << GRAY << "Default constructor called" << RESET << std::endl;
	std::cout << "-------------------------------------"<< std::endl;
}

Span::Span(unsigned int N) : N(N) {
	std::cout << GREEN << "Parameterized constructor called" << RESET << std::endl;
	std::cout << "-------------------------------------"<< std::endl;
}

Span::~Span() {
	std::cout << "-------------------------------------"<< std::endl;
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Span::Span(const Span &copy) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	std::cout << "-------------------------------------"<< std::endl;
	*this = copy;
}

Span &Span::operator=(const Span &rhs) {
	std::cout << CYAN << "Assignation operator called" << RESET << std::endl;
	std::cout << "-------------------------------------"<< std::endl;
	if (this != &rhs)
	{
		this->N = rhs.N;
		this->contents = rhs.contents;
	}
	return *this;
}

unsigned int Span::size(void) const {
	return this->N;
}

const std::vector<int> &Span::getContents(void) const {
	return this->contents;
}

void Span::addNumber(int number) {
	if (this->contents.size() < this->N)
		this->contents.push_back(number);
	else
		throw (Span::FullContainerException());
}

void Span::printContents(void) const {
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator end = this->contents.end();
	std::cout << MAGENTA << "------[Contents]-----" << RESET << std::endl;
	for (it = this->contents.begin(); it < end; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

unsigned int Span::shortestSpan(void) const {
	if (this->contents.size() < 2)
		throw (Span::NotEnoughNumbersException());

	std::vector<int> sorted = this->contents;
	std::sort(sorted.begin(), sorted.end());

    std::vector<int>::const_iterator it = sorted.begin();

	unsigned int shortest = *(it + 1) - *it;
	for (it = std::next(it); it != sorted.end(); ++it) {
		shortest = std::min(shortest, static_cast<unsigned int>(*it - *(std::prev(it))));
	}
	return shortest;
}

unsigned int Span::longestSpan(void) const {
	if (this->contents.size() < 2)
		throw (Span::NotEnoughNumbersException());

	std::vector<int> sorted = this->contents;
	std::sort(sorted.begin(), sorted.end());

	std::vector<int>::const_iterator it = sorted.begin();

	unsigned int longest = *(std::prev(sorted.end())) - *it;

	return longest;
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	while (begin < end){
		try{
			this->addNumber(*begin);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		begin++;
	}
}


