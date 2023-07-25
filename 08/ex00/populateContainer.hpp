/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populateContainer.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:24:52 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/25 11:10:36 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <vector>
#include <list>
#include <deque>
#include <iostream>

template <typename T>
void	populateContainer(T& container, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		int	r = rand() %MAGNITUDE;
		std::cout << r << " ";
		container.push_back(r);
	}
	std::cout << std::endl;
}
