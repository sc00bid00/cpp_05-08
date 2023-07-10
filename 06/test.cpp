/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:58:28 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/10 20:59:24 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>

# define ERR_CONVERTIBLE	"impossible"
# define ERR_DISPLAYABLE		"Non displayable"

/* true if the numeral has a fractional part, requires cmath */
bool	hasFractionalPart(double value) {
	double integerPart;
	double fractionalPart = std::modf(value, &integerPart);
	return fractionalPart != 0.0;
}

bool	isDigit(char c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

/* true if a valid float */
int	isValidFloat(std::string literal) {
	float	result;
	int		pointFlag = 0;
	int		eFlag = 0;
	int		status = 0b000;

	if (literal[literal.length() - 1] != 'f')
		return false;
	literal.erase(literal.length() - 1);
	std::istringstream	iss(literal);
	for (unsigned long i = 0; i < literal.length(); i++) {
		if (isDigit(literal[i]) || (!pointFlag && literal[i] == '.') || (!eFlag && literal[i] == 'e')) {
			if (literal[i] == '.')
				pointFlag |= 1;
			if (literal[i] == 'e')
				eFlag |= 1;
		}
		else
			return 0;
	}
	iss >> result;
	float f = static_cast<float>(result);
	if (f == INFINITY || f == -INFINITY)
		return false;
	return true;
}

/* true if a valid double */
bool isDouble(std::string)

void	stringToOther(const std::string& str) {
		std::istringstream iss(str);
		double result;
		iss >> result;
		if (!result && str != "0" && str.length() > 1) {
			std::cerr << "double : " << ERR_CONVERTIBLE << std::endl;
		}
		else if (result || str == "0") {
				std::cout << "double : " << result << std::endl;
				std::cout << "float  : " << static_cast<float>(result) << std::endl;
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
			std::cerr << "double : " << ERR_CONVERTIBLE << std::endl;
			std::cerr << "float  : " << ERR_CONVERTIBLE << std::endl;
			std::cerr << "int    : " << ERR_CONVERTIBLE << std::endl;
			if (static_cast<int>(str[0]) > 32 && static_cast<int>(str[0]) < 127)
				std::cout << "char   : " << str[0] << std::endl;
			else
				std::cerr << "char   : " << ERR_DISPLAYABLE << std::endl;
		}
	}

int main(void) {
	std::string input;
	std::cout << "Enter a string: ";
	std::cin >> input;
	if (isValidFloat(input))
		std::cout << "Input is a float" << std::endl;
	else
		std::cout << "Input is not a float" << std::endl;
	// stringToOther(input);
	// std::cout << "double max : " << std::numeric_limits<double>::max() << std::endl;
	// std::cout << "double min : " << std::numeric_limits<double>::min() << std::endl;
	// std::cout << "float max : " << std::numeric_limits<float>::max() << std::endl;
	// std::cout << "float min : " << std::numeric_limits<float>::min() << std::endl;
	// std::cout << "int max : " << std::numeric_limits<int>::max() << std::endl;
	// std::cout << "int min : " << std::numeric_limits<int>::min() << std::endl;
	return 0;
}
