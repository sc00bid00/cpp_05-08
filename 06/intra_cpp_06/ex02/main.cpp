/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:30:14 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/12 19:23:53 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void) {
	/* Identify by pointer */
	Base*	ptr_1 = generate();	// Generated : 'X' pointer
	identify(ptr_1);			// Identified instance of class 'X' by reference !
	delete ptr_1;

	/* Identify by reference */
	Base*	ptr_2 = generate();	// Generated : 'X' pointer
	identify(*ptr_2);			// Identified instance of class 'X' by reference !
	delete ptr_2;

	/* Fail test - this class is not A, B, or C */
	Base* ptr_3 = new Base;
	identify(ptr_3);	// No known type identified !
	identify(*ptr_3);	// No known type identified !
	delete ptr_3;
	return 0;
}
