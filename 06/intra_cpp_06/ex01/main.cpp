/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:45:32 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/11 15:16:44 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data		dataPtr;
	uintptr_t	ptrIntValue;

	dataPtr.someString = "this is the original text";
	dataPtr.someInt = 100;

	std::cout << BBLUE << "dataPtr       carries '" << dataPtr.someString << "' and '" << dataPtr.someInt << "'" << RESET << std::endl;
	std::cout << BYELLOW << "Address of dataPtr : " << &dataPtr << RESET << std::endl;
	ptrIntValue = Serializer::serialize(&dataPtr);
	std::cout << BPURPLE << "Serialized dataPtr : " << ptrIntValue << RESET << std::endl;
	Data* dataPtrReturn = Serializer::deserialize(ptrIntValue);
	std::cout << BYELLOW << "Deserialized value : " << dataPtrReturn << RESET << std::endl;
	std::cout << BGREEN << "dataPtrReturn carries '" << dataPtrReturn->someString << "' and '" << dataPtrReturn->someInt << "'" << RESET << std::endl;
	return 0;
}
