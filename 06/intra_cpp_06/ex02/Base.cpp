/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:27:02 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/12 19:28:50 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {
	if (VERBOSE)
		std::cout << BBLUE << "Base destructor called" << RESET << std::endl;
}

Base*	generate(void) {
	srand(time(NULL));
	int	i = rand() %3;
	switch (i) {
		case 0:
			std::cout << BPURPLE << "Generated : A pointer" << RESET << std::endl;
			return new A();
		case 1:
			std::cout << BYELLOW << "Generated : B pointer" << RESET << std::endl;
			return new B();
		case 2:
			std::cout << BGREEN << "Generated : C pointer" << RESET << std::endl;
			return new C();
	}
	return NULL;
}

void	identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << BPURPLE << "Identified instance of class A by pointer !" << RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << BYELLOW<< "Identified instance of class B by pointer !" << RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << BGREEN << "Identified instance of class C by pointer !" << RESET << std::endl;
	else
		std::cerr << BRED << ERR_IDENTIFY << RESET << std::endl;
}

void	identify(Base& ptr) {
	try {
		A&	a = dynamic_cast<A &>(ptr);
		std::cout << BPURPLE << "Identified instance of class A by reference !" << RESET << std::endl;
		(void)a;
	}
	catch (std::exception &e_1) {
		try {
			B&	b = dynamic_cast <B &>(ptr);
			std::cout << BYELLOW << "Identified instance of class B by reference !" << RESET << std::endl;
			(void)b;
		}
		catch (std::exception &e_2) {
			try {
				C&	c = dynamic_cast <C &>(ptr);
				std::cout << BGREEN << "Identified instance of class C by reference !" << RESET << std::endl;
				(void)c;
			}
			catch (std::exception &e_3) {
				std::cerr << BRED << ERR_IDENTIFY << RESET << std::endl;
			}
		}
	}
}
