/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:30:14 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/11 16:30:12 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Colors.hpp"

Base*	generate(void) {
	srand(time(NULL));
	int	i = rand() %3;
	if (i == 0) {
		A*	a = new A;
		std::cout << BYELLOW << "Generated : A pointer" << std::endl;
		return (reinterpret_cast<Base *>(a));
	}
	else if (i == 1) {
		std::cout << BYELLOW << "Generated : B pointer" << std::endl;
		B*	b = new B;
		return (reinterpret_cast<Base *>(b));
	}
	else if (i == 2) {
		std::cout << BYELLOW << "Generated : C pointer" << std::endl;
		C*	c = new C;
		return (reinterpret_cast<Base *>(c));
	}
	return NULL;
}

// void	identify(Base* p) {
// 	if (A* a = dynamic_cast<A *>(p))
// 		std::cout << BGREEN << "Identified instance of class A !" << RESET << std::endl;
// 	else if (B* b = dynamic_cast<B *>(p))
// 		std::cout << BGREEN << "Identified instance of class B !" << RESET << std::endl;
// 	else if (C* c = dynamic_cast<C *>(p))
// 		std::cout << BGREEN << "Identified instance of class C !" << RESET << std::endl;
// 	else
// 		std::cout << BRED << "Cannot identify what this is pointing at !" << RESET << std::endl;
// }

void	identify(Base& ptr) {
	std::cout << &ptr << std::endl;
	A	a;
	std::cout << reinterpret_cast<a&>(&ptr) << std::endl;
}


int	main(void) {
	// /* TEST pointer identification */
	// Base*	ptr = generate();
	// std::cout << ptr << std::endl;
	// identify(ptr);
	/* TEST reference indentification */
	Base*	ptr = generate();
	std::cout << ptr << std::endl;
	identify(*ptr);
	// identify(*ptr);
	delete ptr;
	return 0;
}
