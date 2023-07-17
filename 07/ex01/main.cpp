/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:29:16 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/17 15:56:27 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "iter.hpp"

int	main(void)	{
	int arrayOfInts[3] = {21, 42, 63};
	::iter<int, void>(arrayOfInts, 3, function);

	float arrayOfFloats[3] = {21.0f, 42.0f, 63.0f};
	::iter<void>(arrayOfFloats, 3, function);
	::iter<float, void>(arrayOfFloats, 3, function);

	std::string arrayOfStrings[2] = {"Hello", "World"};
	::iter<std::string, void>(arrayOfStrings, 2, function);

	double arrayOfDoubles[3] = {21.0, 42.0, 63.0};
	::iter<double, void>(arrayOfDoubles, 3, function);

	char	arrayOfChars[3] = {'z', 'w', 'v'};
	::iter<char, void>(arrayOfChars, 3, function);

	return 0;
}
