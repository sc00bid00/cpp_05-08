/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:19:25 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/17 15:51:59 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define VERBOSE	false
# include "function.hpp"

template<typename T, typename V>
void	iter(T* address, size_t length, V function(T&)) {
	if (VERBOSE)
		std::cout << "General iter template" << std::endl;
	if (address && function)
		for (size_t i = 0; i < length; i++) {
			function(address[i]);
			std::cout << address[i] << std::endl;
		}
}

template<typename V>
void	iter(float* address, size_t length, V function(float&)) {
	if (VERBOSE)
		std::cout << "Specialized iter template" << std::endl;
	if (address && function)
		for (size_t i = 0; i < length; i++) {
			function(address[i]);
			std::cout << std::fixed << std::setprecision(1) << address[i] << "f" << std::endl;
		}
}

