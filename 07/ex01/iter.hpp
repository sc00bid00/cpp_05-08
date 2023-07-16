/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:19:25 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/16 18:15:29 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T, typename U, typename V>
void	iter(T& address, U const& length, V const& function) {
	for (U i = 0; i < length; i++) {
		function(*(address + i));
	}
}

template<typename T, typename Z>
T const& function(Z&);

template<typename T>
T const& function(std::string&);
template<typename T>
T const& function(int&);
template<typename T>
T const& function(float&);
