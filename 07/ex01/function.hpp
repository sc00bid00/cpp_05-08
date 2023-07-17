/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:16:59 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/17 15:56:14 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <exception>
# include <iomanip>

template <typename W>
void function(W& arg) {
	arg /= 2;
};

template <>
void function(std::string& arg) {
	arg += "_touched";
};


