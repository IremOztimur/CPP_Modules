/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:23:40 by ioztimur          #+#    #+#             */
/*   Updated: 2024/03/06 21:07:25 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Orthodox Form
ScalarConverter::ScalarConverter() :  _char(0), _int(0), _float(0.0f), _double(0.0), input("DEFAULT"){
	std::cout << GRAY << "Default Constructor Called" << RESET << std::endl;
	std::cout << "--------------------------------------" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string input) :  _char(0), _int(0), _float(0.0f), _double(0.0), input(input){
	std::cout << GREEN << "ScalarConverter Constructor Called" << RESET << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	this->setType();
	if (this->getType() == NONE)
		throw UnknownTypeException();
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) : input(src.input){
	std::cout << YELLOW << "Copy Constructor Called" << RESET << std::endl;
	std::cout << "--------------------------------------" << std::endl;
}

ScalarConverter::~ScalarConverter(){
	std::cout << "--------------------------------------" << std::endl;
	std::cout << RED << "Destructor Called" << RESET << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs){
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Assignment Operator Called" << std::endl;
	if (this != &rhs){
		this->_int = rhs.getInt();
		this->_float = rhs.getFloat();
		this->_double = rhs.getDouble();
		this->_char = rhs.getChar();
	}
	return *this;
}




// Getters
s_type		ScalarConverter::getType(void) const{
	return this->type;
}

std::string	ScalarConverter::getInput(void) const{
	return this->input;
}

char		ScalarConverter::getChar(void) const{
	return this->_char;
}

int		ScalarConverter::getInt(void) const{
	return this->_int;
}

float		ScalarConverter::getFloat(void) const{
	return this->_float;
}

double		ScalarConverter::getDouble(void) const{
	return this->_double;
}




// Setters
void		ScalarConverter::setChar(char _char){
	this->_char = _char;
}

void		ScalarConverter::setInt(int _int){
	this->_int = _int;
}

void		ScalarConverter::setFloat(float _float){
	this->_float = _float;
}

void		ScalarConverter::setDouble(double _double){
	this->_double = _double;
}

void		ScalarConverter::setType(){
	if (isChar())
		type = CHAR;
	else if (isInt())
		type = INT;
	else if (isFloat())
		type = FLOAT;
	else if (isDouble())
		type = DOUBLE;
	else if (isLiteral())
		type = LITERAL;
	else
		type = NONE;
}



// Exceptions
const char *ScalarConverter::UnknownTypeException::what() const throw(){
	return "IMPOSSIBLE (In italian Accent)";
}


// Checkers
bool ScalarConverter::isChar(void) const{
	if (input.length() == 1 && !isdigit(input[0]) && isalpha(input[0]) && std::isprint(input[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(void) const{
	if (input.length() == 1 && isdigit(input[0]))
		return true;
	if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-' || input[0] == '+')){
		for (size_t i = 1; i < input.length(); i++){
			if (!isdigit(input[i]))
				return false;
		}
		return true;
	}
	return false;
}

bool ScalarConverter::isFloat(void) const{
	if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-' || input[0] == '+')){
		for (size_t i = 1; i < input.length(); i++){
			if ((!isdigit(input[i]) && input[i] != '.') && (!isdigit(input[i]) && input[i] != 'f'))
				return false;
		}
		return true;
	}
	return false;
}


bool ScalarConverter::isLiteral(void) const{
	if ((this->impossible) || (input.compare("nan") == 0) || (input.compare("+inf") == 0) || (input.compare("-inf") == 0)
	|| (input.compare("-inff") == 0) || (input.compare("+inff") == 0) || (input.compare("nanf") == 0))
		return true;
	return false;
}

bool ScalarConverter::isImpossible(void){
	try {
		if (type == INT)
			this->_int = std::stoi(input);
		else if (type == FLOAT)
			this->_float = std::stof(input);
		else if (type == DOUBLE)
			this->_double = std::stod(input);
		else if (type == CHAR)
			this->_char = input[0];
	}
	catch (std::exception &e){
		this->impossible = true;
		return true;
	}
	return false;
}

bool ScalarConverter::isDouble(void) const{
	if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-' || input[0] == '+')){
		for (size_t i = 1; i < input.length(); i++){
			if ((!isdigit(input[i]) && input[i] != '.'))
				return false;
		}
		return true;
	}
	return false;
}


// Printers
void ScalarConverter::printChar(void) const{
	if (this->isLiteral() || (!std::isprint(this->_int) && (this->_int >= 127)))
		std::cout << "Impossible";
	else if (!std::isprint(this->_int))
		std::cout << "Non displayable";
	else
		std::cout << "'" << this->getChar() << "'";
	std::cout << std::endl;
}

void ScalarConverter::printInt(void) const{
	if (this->isLiteral() || (!std::isprint(this->_int) && (this->_int >= 127)))
		std::cout << "Impossible";
	else
		std::cout << this->getInt();
	std::cout << std::endl;
}

void ScalarConverter::printFloat(void) const{
	if (!input.compare("nan") || !input.compare("nanf"))
		std::cout << "nanf";
	else if (!input.compare("+inf") || !input.compare("+inff"))
		std::cout << "+inff";
	else if (!input.compare("-inf") || !input.compare("-inff"))
		std::cout << "-inff";
	else
		if (_float - static_cast<int>(_float) == 0)
			std::cout << this->getFloat() << ".0f";
		else
			std::cout << this->getFloat() << "f";
	std::cout << std::endl;
}

void	ScalarConverter::printDouble(void) const{
	if (!input.compare("nan") || !input.compare("nanf"))
		std::cout << "nan";
	else if (!input.compare("+inf") || !input.compare("+inff"))
		std::cout << "+inf";
	else if (!input.compare("-inf") || !input.compare("-inff"))
		std::cout << "-inf";
	else
		if (_double - static_cast<int>(_double) == 0)
			std::cout << this->getDouble() << ".0";
		else
			std::cout << this->getDouble();
	std::cout << std::endl;

}


// Converter Method

void	ScalarConverter::convert(void)
{
	if (this->isImpossible())
		return;
	switch (type)
	{
		case CHAR:
			_char = input[0];
			_int = static_cast<int>(_char);
			_float = static_cast<float>(_char);
			_double = static_cast<double>(_char);
			break;
		case INT:
			_int = std::stoi(input);
			_char = static_cast<char>(_int);
			_float = static_cast<float>(_int);
			_double = static_cast<double>(_int);
		case FLOAT:
			_float = std::stof(input);
			_char = static_cast<char>(_float);
			_int = static_cast<int>(_float);
			_double = static_cast<double>(_float);
		case DOUBLE:
			_double = std::stod(input);
			_char = static_cast<char>(_double);
			_int = static_cast<int>(_double);
			_float = static_cast<float>(_double);
		default:
				break;
	}
}


std::ostream &operator<<(std::ostream &out, const ScalarConverter &rhs){
	out << YELLOW << "char: " << RESET;  rhs.printChar();
	out << YELLOW << "int: " << RESET; rhs.printInt();
	out << YELLOW << "float: " << RESET; rhs.printFloat();
	out << YELLOW << "double: "<< RESET; rhs.printDouble();
	return out;
}
