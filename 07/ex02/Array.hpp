/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:06:12 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/18 13:41:13 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <exception>
# include "Colors.hpp"

# define EXC_NOACCESS "Error: out of bounds access !"

template<typename T>
class	Array {
	private:

/* === ATTRIBUTES === */

		unsigned int	_arrayElements;
		T*				_array;

	public:

/* === CANONICAL IMPLEMENTATION === */

		Array(void) : _arrayElements(0), _array(new T[_arrayElements]) {
			if (VERBOSE)
				std::cout << "Array default constructor called" << std::endl;
		}
		Array(unsigned int n) : _arrayElements(n), _array(new T[_arrayElements]) {
			if (VERBOSE)
				std::cout << "Array unsigned int constructor called" << std::endl;
		}
		Array(Array const& src) {
			if (VERBOSE)
				std::cout << "Array copy constructor called" << std::endl;
			*this = src;
		}
		~Array(void) {
			if (VERBOSE)
				std::cout << "Array destructor called" << std::endl;
			delete[] this->_array;
		};
		Array const& operator=(Array const& rhs) {
			if (VERBOSE)
				std::cout << "Array = operator called" << std::endl;
			this->_array = new T(rhs._arrayElements);
			*this->_array = *rhs._array;
		}

/* === OPERATORS === */

		T&	operator[](unsigned int n) {
			if (VERBOSE)
				std::cout << "Array [] operator called" << std::endl;
			if (n >=0 && n < this->_arrayElements)
				return this->_array[n];
			else throw NoAccessException();
		}

/* === FUNCTIONS === */

		unsigned int	size(void) const {
			return this->_arrayElements;
		}


/* === EXCEPTION === */

		class	NoAccessException : public std::exception {
			public:
				virtual char const* what() const throw();
		};
};

template<typename T>
char const* Array<T>::NoAccessException::what() const throw() {
					return EXC_NOACCESS;
		}
