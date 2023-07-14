/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_4.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:31:58 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/14 09:03:27 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

bool hasFractionalPart(double value) {
	double integerPart;
	double fractionalPart = std::modf(value, &integerPart);
	return fractionalPart != 0.0;
}

int main() {
	double num1 = 5.0;
	double num2 = 5.5;
	double num3 = 1e18;

	std::cout << num1 << " has a fractional part? " << (hasFractionalPart(num1) ? "Yes" : "No") << std::endl;
	std::cout << num2 << " has a fractional part? " << (hasFractionalPart(num2) ? "Yes" : "No") << std::endl;
	std::cout << num3 << " has a fractional part? " << (hasFractionalPart(num3) ? "Yes" : "No") << std::endl;

	return 0;
}
