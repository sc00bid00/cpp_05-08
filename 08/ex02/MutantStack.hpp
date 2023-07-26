/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:42:58 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/26 18:06:33 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Macros.hpp"
# include <stdexcept>
# include <stack>
# include <iostream>
# include <deque>
# include <vector>
# include <list>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
	public:
		MutantStack(void) {
			if (VERBOSE)
				std::cout << BBLUE << "MutantStack default constructor called" << RESET << std::endl;
		}
		MutantStack(MutantStack& src) {
			if (VERBOSE)
				std::cout << BBLUE << "MutantStack copy constructor called" << RESET << std::endl;
			*this = src;
		}
		~MutantStack(void) {
			if (VERBOSE)
				std::cout << BBLUE << "MutantStack destructor called" << RESET << std::endl;
		}
		MutantStack&	operator=(MutantStack const& rhs) {
			if (VERBOSE)
				std::cout << BBLUE << "MutantStack operator= called" << RESET << std::endl;
			if (this != &rhs)
				*this = rhs;
			return (*this);
		}

		typedef typename C::iterator iterator;
		iterator	begin(void) {
			return this->c.begin();
		};
		iterator	end(void) {
			return this->c.end();
		};

		class	EmptyStackException : public std::exception {
			public:
				char const*	what() const throw() {return ERR_EMPTY_STACK;}
		};
		void	safePop(void) {
			try {
				if (!this->empty())
					this->pop();
				else
					throw	EmptyStackException();
			}
			catch (std::exception &e){
				std::cout << BRED << e.what() << RESET << std::endl;
			}
		}
		T	safeTop(void) {
			try {
				if (!this->empty())
					return this->top();
				else
					throw	EmptyStackException();
			}
			catch (std::exception &e){
				std::cout << BRED << e.what() << RESET << std::endl;
			}
			return 0;
		}
};
