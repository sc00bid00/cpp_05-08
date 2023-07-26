/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:39:33 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/26 09:57:00 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* === CANONICAL IMPLEMENTATION === */

Span::Span(void) : _N(0) {
	if (VERBOSE)
		std::cout << BBLUE << "Span default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
	if (VERBOSE)
		std::cout << BBLUE << "Span N constructor called" << RESET << std::endl;
}

Span::Span(Span& src) {
	if (VERBOSE)
		std::cout << BBLUE << "Span copy constructor called" << RESET << std::endl;
	*this = src;
}

Span::~Span(void) {
	if (VERBOSE)
		std::cout << BBLUE << "Span destructor called" << RESET << std::endl;
}

Span&	Span::operator=(Span& rhs) {
	if (VERBOSE)
		std::cout << BBLUE << "Span operator= called" << RESET << std::endl;
	if (this != &rhs) {
		this->_N = rhs._N;
		this->_spanVector = rhs._spanVector;
	}
	return *this;
}

/* === FUNCTIONS === */

std::vector<int>&	Span::getVectorReference(void)  {
	return this->_spanVector;
}

bool	Span::_IsSpace(void) const {
	if (this->_spanVector.size() < this->_N)
		return true;
	return false;
}

bool	Span::_IsEmpty(void) const {
	if (this->_spanVector.size() < 2)
		return true;
	return false;
}

void		Span::addNumber(int const number) {
	try {
		if (this->_IsSpace())
			this->_spanVector.push_back(number);
		else
			throw FullContainerException();
	}
	catch (std::exception &e) {
		std::cout << BRED << e.what() << RESET << std::endl;
	}
}

void		Span::addInBulk() {
	while (this->_spanVector.size() < this->_N) {
		int	r = rand() %RDN_MAGNITUDE;
		this->_spanVector.push_back(r);
	}
}

int		Span::shortestSpan(void) {
	try {
		if (!this->_IsEmpty()) {
			int minSpan = abs(*(this->_spanVector.end()-1) - *this->_spanVector.begin());
			std::sort(this->_spanVector.begin(), this->_spanVector.end());
			for (std::vector<int>::const_iterator it = this->_spanVector.begin(); it != this->_spanVector.end() - 1; ++it) {
				if (abs(*it - *(it + 1)) < minSpan)
					minSpan = abs(*it - *(it + 1));
			}
		return minSpan;
		}
		else
			throw EmptyContainerException();
	}
	catch (std::exception &e) {
		std::cout << BRED << e.what() << RESET << std::endl;
	}
	return -1;
}

int		Span::longestSpan(void) {
	try {
		if (!this->_IsEmpty()) {
			int minElement = *std::min_element(this->_spanVector.begin(), this->_spanVector.end());
			int maxElement = *std::max_element(this->_spanVector.begin(), this->_spanVector.end());
			int maxSpan = maxElement - minElement;
			return maxSpan;
		}
		else
			throw EmptyContainerException();
	}
	catch (std::exception &e) {
		std::cout << BRED << e.what() << RESET << std::endl;
	}
	return -1;
}

char const*	Span::FullContainerException::what() const throw() {
	return ERR_FULL_CONTAINER;
}

char const*	Span::EmptyContainerException::what() const throw() {
	return ERR_EMPTY_CONTAINER;
}

std::ostream&	operator<<(std::ostream& o, Span& src) {
	std::cout << BPURPLE << "Container size        : " << src.getVectorReference().size() << RESET << std::endl;
	std::cout << BPURPLE << "Min element contained : " << *std::min_element(src.getVectorReference().begin(), src.getVectorReference().end()) << RESET << std::endl;
	std::cout << BPURPLE << "Max element contained : " << *std::max_element(src.getVectorReference().begin(), src.getVectorReference().end()) << RESET << std::endl;
	return o;
}
