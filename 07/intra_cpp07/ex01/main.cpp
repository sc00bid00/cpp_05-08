/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:29:16 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/18 16:24:19 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename W>
void function(W& arg) {
	arg /= 2;
};

template <>
void function(std::string& arg) {
	arg += "_touched";
};


int	main(void)	{
	int arrayOfInts[3] = {21, 42, 63};
	iter(arrayOfInts, 3, function<int>);
	for (int i = 0; i < 3; i++)
		std::cout << arrayOfInts[i] << std::endl;

	float arrayOfFloats[3] = {21.0f, 42.0f, 63.0f};
	iter(arrayOfFloats, 3, function<float>);
	for (int i = 0; i < 3; i++)
		std::cout << arrayOfFloats[i] << std::endl;

	std::string arrayOfStrings[2] = {"Hello", "World"};
	iter(arrayOfStrings, 2, function<std::string>);
	for (int i = 0; i < 2; i++)
		std::cout << arrayOfStrings[i] << std::endl;

	double arrayOfDoubles[3] = {21.0, 42.0, 63.0};
	iter(arrayOfDoubles, 3, function<double>);
	for (int i = 0; i < 3; i++)
		std::cout << arrayOfDoubles[i] << std::endl;

	char	arrayOfChars[3] = {'z', 'w', 'v'};
	iter(arrayOfChars, 3, function<char>);
	for (int i = 0; i < 3; i++)
		std::cout << arrayOfChars[i] << std::endl;

	return 0;
}
