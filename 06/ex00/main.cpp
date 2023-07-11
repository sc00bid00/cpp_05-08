/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:17:18 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/11 11:24:49 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << BRED << ERR_ARGNUM << std::endl;
		return 1;
	}
	ScalarConverter	converter;
	converter.convert(argv[1]);
	return 0;
}