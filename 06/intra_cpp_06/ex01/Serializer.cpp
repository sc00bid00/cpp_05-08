/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:22:39 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/11 15:15:33 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* === CANONICAL IMPLEMENTATION === */

Serializer::Serializer(void) {
	if (VERBOSE)
		std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(Serializer const& src) {
	if (VERBOSE)
		std::cout << "Serializer copy constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer(void) {
	if (VERBOSE)
		std::cout << "Serializer destructor called" << std::endl;
}

Serializer&	Serializer::operator=(Serializer const& rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

/* === METHODS IMPLEMENTATION === */

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t	ptrIntValue = reinterpret_cast<uintptr_t>(ptr);
	return ptrIntValue;
}

Data*		Serializer::deserialize(uintptr_t raw) {
	Data*	dataPtr;

	dataPtr = reinterpret_cast<Data *>(raw);
	return dataPtr;
}
