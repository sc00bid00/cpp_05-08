/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:27:02 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/11 19:12:31 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void) {
	if (VERBOSE)
		std::cout << BBLUE << "Base destructor called" << RESET << std::endl;
}
