/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:11:24 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/18 16:02:59 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int	main(void) {

	/* subject main */
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c , d ) << std::endl;


	// /* my main */
	// int	a = 21;
	// int	b = 42;

	// std::cout << "First value : " << a << "		Second Value : " << b << std::endl;
	// swap(a, b);
	// std::cout << "First value : " << a << "		Second Value : " << b << std::endl;
	// std::cout << "Min of " << a << " and " << b << " is " << min( a , b ) << std::endl;
	// std::cout << "Max of " << a << " and " << b << " is " << max( a , b ) << std::endl;
	// float	e = 21.21f;
	// float	f = 42.42f;

	// std::cout << "Min of " << e << " and " << f << " is " << min( e , f ) << std::endl;
	// std::cout << "Max of " << e << " and " << f << " is " << max( e , f ) << std::endl;

	// std::string	c = "Twentyone";
	// std::string	d = "Fortytwo";

	// std::cout << "First value : " << c << "		Second Value : " << d << std::endl;
	// swap(c, d);
	// std::cout << "First value : " << c << "		Second Value : " << d << std::endl;

	// int	x = 42;
	// int	y = 42;
	// std::cout << "x : " << x << " ( " << &x << " )" <<std::endl;
	// std::cout << "y : " << y << " ( " << &y << " )" <<std::endl;
	// std::cout << "Min of " << x << " and " << y << " is " << min( x , y ) << " ( " << &min( x, y ) << " )" << std::endl;
	// std::cout << "Max of " << x << " and " << y << " is " << max( x , y ) << " ( " << &max( x, y ) << " )" << std::endl;

	return 0;
}
