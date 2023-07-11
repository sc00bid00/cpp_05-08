/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:30:14 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/11 19:14:08 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	srand(time(NULL));
	int	i = rand() %3;
	if (i == 0) {
		A*	a = new A;
		std::cout << BPURPLE << "Generated : A pointer" << RESET << std::endl;
		return (reinterpret_cast<Base *>(a));
	}
	else if (i == 1) {
		B*	b = new B;
		std::cout << BYELLOW << "Generated : B pointer" << RESET << std::endl;
		return (reinterpret_cast<Base *>(b));
	}
	else if (i == 2) {
		std::cout << BGREEN << "Generated : C pointer" << RESET << std::endl;
		C*	c = new C;
		return (reinterpret_cast<Base *>(c));
	}
	return NULL;
}

void	identifyByPtr(Base* p) {
	if (A* a = dynamic_cast<A *>(p))
		std::cout << BPURPLE << "Identified instance of class A by pointer !" << RESET << std::endl;
	else if (B* b = dynamic_cast<B *>(p))
		std::cout << BYELLOW<< "Identified instance of class B by pointer !" << RESET << std::endl;
	else if (C* c = dynamic_cast<C *>(p))
		std::cout << BGREEN << "Identified instance of class C by pointer !" << RESET << std::endl;
}

void	identifyByRef(Base& ptr) {
	try {
		A&	a = dynamic_cast<A &>(ptr);
		std::cout << BPURPLE << "Identified instance of class A by reference !" << RESET << std::endl;
		(void)a;
	}
	catch (std::bad_cast &bc_1) {
		try {
			B&	b = dynamic_cast <B &>(ptr);
			std::cout << BYELLOW << "Identified instance of class B by reference !" << RESET << std::endl;
			(void)b;
		}
		catch (std::bad_cast &bc_2) {
			C&	c = dynamic_cast <C &>(ptr);
			std::cout << BGREEN << "Identified instance of class C by reference !" << RESET << std::endl;
			(void)c;
		}
	}
}


int	main(void) {
	/* Indentify by pointer */
	Base*	ptr_1 = generate();
	identifyByPtr(ptr_1);
	delete ptr_1;

	/* Indentify by reference */
	Base*	ptr_2 = generate();
	identifyByRef(*ptr_2);
	delete ptr_2;
	return 0;
}
