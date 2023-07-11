/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:58:43 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/11 11:25:50 by lsordo           ###   ########.fr       */
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

std::string	formatOutputDouble(double result) {
	std::stringstream	ss;
	ss << std::fixed << std::setprecision(D_PRECISION) << result;
	std::string strValue = ss.str();
	if (result == INFINITY || result == -INFINITY)
		return strValue;
	std::string::size_type	posE = strValue.find('e');
	if (posE != std::string::npos)
		return strValue;
	std::string::size_type	posDot = strValue.find('.');
	if (posDot != std::string::npos)
		return strValue;
	return (strValue + ".0");
}

std::string	formatOutputFloat(double result) {
	std::stringstream	ss;
	ss << std::fixed << std::setprecision(F_PRECISION) << result;
	std::string strValue = ss.str();
	if (result == INFINITY || result == -INFINITY)
		return (strValue + "f");
	std::string::size_type	posE = strValue.find('e');
	if (posE != std::string::npos)
		return (strValue + "f");
	std::string::size_type	posDot = strValue.find('.');
	if (posDot != std::string::npos)
		return (strValue + "f");
	return (strValue + ".0f");
}

void	ScalarConverter::convert(std::string str) {
		if (str.length() > 1 && str[str.length() - 1] == 'f')
		str.erase(str.length() - 1);
	std::istringstream iss(str);
	double result;
	iss >> result;
	if (!result && str != "0" && str.length() > 1) {
		std::cerr << "double : " << ERR_CONVERTIBLE << std::endl;
	}
	else if (result || str == "0") {
			std::cout << "double : " << formatOutputDouble(result) << std::endl;
			std::cout << "float  : " << formatOutputFloat(static_cast<float>(result)) << std::endl;
		if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min() ) {
			std::cerr << "int    : " << ERR_CONVERTIBLE << std::endl;
			std::cerr << "char   : " << ERR_CONVERTIBLE << std::endl;
		}
		else
			{
				int resultInt = static_cast<int>(result);
				std::cout << "int    : " << resultInt << std::endl;
				if (resultInt > 255)
					std::cerr << "char   : " ERR_CONVERTIBLE << std::endl;
				else if (resultInt > 32 && resultInt < 126 )
					std::cout << "char   : " << static_cast<char>(resultInt) << std::endl;
				else
					std::cerr << "char   : " << ERR_DISPLAYABLE << std::endl;
			}
	}
	else if(!result && str.length() == 1) {
		std::cerr << "double : " << formatOutputDouble(static_cast<double>(static_cast<char>(str[0]))) << std::endl;
		std::cerr << "float  : " << formatOutputFloat(static_cast<float>(static_cast<char>(str[0]))) << std::endl;
		std::cerr << "int    : " << static_cast<int>(static_cast<char>(str[0]))<< std::endl;
		if (static_cast<int>(str[0]) > 32 && static_cast<int>(str[0]) < 127)
			std::cout << "char   : " << str[0] << std::endl;
		else
			std::cerr << "char   : " << ERR_DISPLAYABLE << std::endl;
	}
}
