/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:29:16 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/16 18:12:53 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void	function(int& x) {
	x *=2;
}
void	function(float& x) {
	x /=2;
}
void	function(std::string& x) {
	x +="_changed";
}

// void	functionString(std::string& x) {
// 	x = x + "_touch";
// }

// void	functionInt(int& x) {
// 	x = x * 2;
// }


int	main(void)	{
	std::string	arrayOfString[3] = {"Hello", "World", "!"};
	::iter(arrayOfString, 3, function);
	// ::iter(arrayOfString, 3, functionString);
	int	arrayOfInt[5] = {21, 42, 63, 84, 106};
	// ::iter(arrayOfInt, 5, functionInt);
	for (int i = 0;i < 3; i++) {
		std::cout << arrayOfString[i] << std::endl;
	}
	for (int i = 0;i < 5; i++) {
		std::cout << arrayOfInt[i] << std::endl;
	}
	return 0;
}
