/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:16:33 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/12 18:26:48 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <iostream>
# include <stdint.h>
# include "Colors.hpp"
# include "Data.hpp"

class	Serializer {
	private:
		Serializer(void);
		Serializer(Serializer const& src);
		~Serializer(void);
		Serializer&	operator=(Serializer const& rhs);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
