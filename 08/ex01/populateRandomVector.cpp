/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populateRandomVector.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:44:32 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/26 12:46:03 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	populateRandomVector(std::vector<int>&	vector) {
	std::vector<int>::iterator	it;
	for (it = vector.begin(); it != vector.end(); ++it)
		*it = rand() %RDN_MAGNITUDE;
}
