/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:39:33 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/25 15:03:02 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* === CANONICAL IMPLEMENTATION === */

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

/* === PRIVATE FUNCTIONS === */

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

/* === FUNCTIONS ==== */

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

int		Span::shortestSpan(void) {
	try {
		if (!this->_IsEmpty()) {
			int minSpan = abs(*this->_spanVector.end() - *this->_spanVector.begin());
			std::sort(this->_spanVector.begin(), this->_spanVector.end());
			for (std::vector<int>::const_iterator it = this->_spanVector.begin(); it != this->_spanVector.end(); ++it) {
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
	return	0;
}

int		Span::longestSpan(void) {
	try {
		if (!this->_IsEmpty()) {
			int maxSpan = abs(*this->_spanVector.end() - *this->_spanVector.begin());
			std::sort(this->_spanVector.begin(), this->_spanVector.end());
			for (std::vector<int>::const_iterator it = this->_spanVector.begin(); it != this->_spanVector.end(); ++it) {
				if (abs(*it - *(it + 1)) > maxSpan)
					maxSpan = abs(*it - *(it + 1));
			}
		return maxSpan;
		}
		else
			throw EmptyContainerException();
	}
	catch (std::exception &e) {
		std::cout << BRED << e.what() << RESET << std::endl;
	}
	return 0;
}

char const*	Span::FullContainerException::what() const throw() {
	return ERR_FULL_CONTAINER;
}

char const*	Span::EmptyContainerException::what() const throw() {
	return ERR_EMPTY_CONTAINER;
}
