/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:19:25 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/18 15:58:58 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename T, typename V>
void	iter(T* array, unsigned int length, V function) {
	if (array && function)
		for (unsigned int i = 0; i < length; i++) {
			function(array[i]);
		}
}
