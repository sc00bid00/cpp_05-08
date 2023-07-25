/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:17:31 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/25 15:00:41 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Macros.hpp"
# include <cstdlib>
# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

class	Span {
	private:
		unsigned int		_N;
		std::vector<int>	_spanVector;
		Span(void);
		bool	_IsSpace(void) const;
		bool	_IsEmpty(void) const;

	public:
		Span(unsigned int);
		Span(Span&);
		~Span(void);
		Span&	operator=(Span&);

		void	addNumber(int const);
		int		shortestSpan(void);
		int		longestSpan(void);

		class FullContainerException : public std::exception {
			public:
				virtual char const* what() const throw();
		};

		class EmptyContainerException : public std::exception {
			public:
				virtual char const* what() const throw();
		};
};
