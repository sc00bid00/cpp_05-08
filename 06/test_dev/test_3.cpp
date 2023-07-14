/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_3.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:57:59 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/14 09:03:12 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits>

double stringToDouble(const std::string& str) {
	std::istringstream iss(str);
	double result;
	iss >> result;
	if (!result) {
			std::cerr << "Error converting string to double: " << str << std::endl;
	}
	return result;
}

double stringToFloat(const std::string& str) {
	std::istringstream iss(str);
	float result;
	iss >> result;
	if (!result) {
			std::cerr << "Error converting string to float: " << str << std::endl;
	}
	return result;
}

double stringToChar(const std::string& str) {
	std::istringstream iss(str);
	char result;
	iss >> result;
	if (!result) {
			std::cerr << "Error converting string to char: " << str << std::endl;
	}
	return result;
}

bool	isVisible(std::string literal) {
	if (literal[0] > 33 && literal[0] < 127)
		return true;
	return false;
}

bool	isDigit(std::string literal) {
	if (literal[0] >= '0' && literal[0] <= '9')
		return true;
	return false;
}

bool	isChar(std::string literal) {
	if (literal.length() == 1)
		return true;
	return false;
}



int main() {
	std::string input;
	std::cout << "Enter a string: ";
	std::cin >> input;

	double	value = stringToDouble(input);
	char	value_2 = stringToChar(input);
	float	value_3 = stringToFloat(input);
	if (value) {
		std::cout << "Converted value to double: " << value << std::endl;
	}
	std::cout << "Converted value to char: " << value_2 << std::endl;
	std::cout << "Converted value to float: " << value_3 << std::endl;
	double	value_4 = std::numeric_limits<double>::max();
	if (value_4 > std::numeric_limits<int>::max())
		std::cerr << "Cannot convert to int" << std::endl;
	else {
		int		value_5 = static_cast<int>(value_4);
		std::cout << value_5 << std::endl;
	}


	return 0;
}
