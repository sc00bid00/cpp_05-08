/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:11:10 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/10 18:57:53 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <limits>

bool	specialToken(std::string literal) {
	std::string tokens[8] = {"-inff", "+inff", "inff", "-inf", "+inf", "inf", "nanf", "nan"};
	for (int i = 0; i < 8; i++) {
		if (literal == tokens[i])
			return true;
	}
	return false;
}


int main() {
	// // Literal value
	// std::string	literal = "3.14159";


	// // Determine the type of the literal using typeid
	// const std::type_info& type = typeid(literal);

	// // Print the type name
	// std::cout << "Type of the literal: " << type.name() << std::endl;

	// // convert an print the value
	// int	i = static_cast <int>(literal);
	// std::cout << "int :    " << i << std::endl;

	// char	c = static_cast <char>(literal);
	// std::cout << "char :   " << c << std::endl;

	// float	f = static_cast <float>(literal);
	// std::cout << "float :  " << f << std::endl;

	// double	d = static_cast <double>(literal);
	// std::cout << "double : " << d << std::endl;
	std::cout << "int    min : " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "int    max : " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "float  min : " << std::numeric_limits<float>::min() << std::endl;
	std::cout << "float  max : " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "double min : " << std::numeric_limits<double>::min() << std::endl;
	std::cout << "double max : " << std::numeric_limits<double>::max() << std::endl;
	std::string literal = "42345627184536723467858625467234512645623465545677124612845127845672341";
	std::cout << "length of literal : " << literal.length() << std::endl;
	return 0;
}
