/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:56:40 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/22 15:57:34 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Colors.hpp"
# include <iostream>

class	Awesome {
	private:
		int	_var;
	public:
		Awesome(void) : _var(42) {
			if (VERBOSE)
				std::cout << "Awesome constructor called" << std::endl;
		}
		Awesome(Awesome const& src) {
			if (VERBOSE)
				std::cout << "Awesome copy constructor called" << std::endl;
			*this = src;
		}
		Awesome& operator=(Awesome const& rhs) {
			if (VERBOSE)
				std::cout << "Awesome operator= called" << std::endl;
			if (this != &rhs)
				this->_var = rhs._var;
			return *this;
		}
		~Awesome(void) {
			if (VERBOSE)
				std::cout << "Awesome destructor called" << std::endl;
		}
		int	getVar(void) const {
			return this->_var;
		}
};

std::ostream&	operator<<(std::ostream& o, Awesome const& object) {
	o << object.getVar();
	return o;
}
