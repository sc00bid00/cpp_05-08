/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:06:32 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/16 16:14:39 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void	swap(T& fst, T& snd) {
	T	tmp = fst;
	fst = snd;
	snd = tmp;
}

template<typename T>
T const&	min(T const& x, T const& y) {
	return (y > x ? x : y);
}

template<typename T>
T const&	max(T const& x, T const& y) {
	return (y < x ? x : y);
}
