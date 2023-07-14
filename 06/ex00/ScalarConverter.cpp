/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:22:06 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/14 05:23:50 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* === CANONICAL IMPLEMENTATION === */

ScalarConverter::ScalarConverter(void) {
	if (VERBOSE)
		std::cout << BBLUE << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& src) {
	if (VERBOSE)
		std::cout << BBLUE << "ScalarConverter copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {
	if (VERBOSE)
		std::cout << BBLUE << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter	&	ScalarConverter::operator=(ScalarConverter const& rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

/* === METHOD IMPLEMENTATION === */
std::string	checkChar(int n) {
	std::stringstream	ss;
	if (n >= 0 && n <= 255 && isprint(n)) {
		ss << static_cast<char>(n);
		return ss.str();
	}
	if (n >= 0 && n <= 255)
		return ERR_DISPLAYABLE;
	return ERR_CONVERTIBLE;

}

void	manageInt(long n) {
	std::cout <<  MSG_CHAR << checkChar(static_cast<int>(n)) << RESET << std::endl;
	std::cout <<  MSG_INT << static_cast<int>(n) << RESET << std::endl;
	std::cout <<  MSG_FLOAT << static_cast<float>(n) << ".0f" << RESET << std::endl;
	std::cout <<  MSG_DOUBLE << static_cast<double>(n) << ".0" << RESET << std::endl;

}

bool	isNanf(std::string token) {
	std::string tkn[3] = {"nanf", "+nanf", "-nanf"};
	for (int i = 0; i < 3; i++) {
		if (token == tkn[i])
			return true;
	}
	return false;
}

bool	isNan(std::string token) {
	std::string tkn[3] = {"nan", "+nan", "-nan"};
	for (int i = 0; i < 3; i++) {
		if (token == tkn[i])
			return true;
	}
	return false;
}

bool	isInff(std::string token) {
	std::string tkn[3] = {"inff", "+inff", "-inff"};
	for (int i = 0; i < 3; i++) {
		if (token == tkn[i])
			return true;
	}
	return false;
}

bool	isInf(std::string token) {
	std::string tkn[3] = {"inf", "+inf", "-inf"};
	for (int i = 0; i < 3; i++) {
		if (token == tkn[i])
			return true;
	}
	return false;
}

void	manageSingle(std::string literal) {
	if (isdigit(literal[0]))
	{
		std::cout << MSG_CHAR << literal[0] << RESET << std::endl;
		std::cout << MSG_INT << static_cast<int>(literal[0]) << RESET << std::endl;
		std::cout << MSG_FLOAT << static_cast<float>(literal[0]) << ".0f" << RESET << std::endl;
		std::cout << MSG_DOUBLE << static_cast<double>(literal[0]) << RESET << std::endl;
		}
}

void	ScalarConverter::convert(std::string literal) {
	if (literal.length() == 1)
		manageSingle(literal);
	else {
		char*	lastChar;
		long n = strtol(literal.c_str(), &lastChar, 10);
		if (*lastChar == '\0' && n < std::numeric_limits<int>::max() && n > std::numeric_limits<int>::min())
			manageInt(n);
		else {
			long double ld = strtold(literal.c_str(), &lastChar);
			if (*lastChar == 'f')
				// manageFloat(ld);
			else if (*lastChar == '\0')
				manageDouble(ls);
			else {
				std::cerr << BRED << MSG_CHAR <<  ERR_CONVERTIBLE << RESET << std::endl;
				std::cerr << BRED << MSG_INT << ERR_CONVERTIBLE << RESET << std::endl;
				std::cerr << BRED << MSG_FLOAT << ERR_CONVERTIBLE << ".0f" << RESET << std::endl;
				std::cerr << BRED << MSG_DOUBLE << ERR_CONVERTIBLE << RESET << std::endl;
			}
		}
	}
}
