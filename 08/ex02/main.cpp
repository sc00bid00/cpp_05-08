/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:03:40 by lsordo            #+#    #+#             */
/*   Updated: 2023/07/26 18:41:09 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>

int	main(void) {
	/* === TEST 1 === */
	{
		std::cout << BYELLOW << ">>>> Test #1 subject's main" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	/* === TEST 2 === */
	{
		std::cout << BYELLOW << ">>>> Test #2 int deque, safe functions" << RESET << std::endl;
		MutantStack<int>	zombie;

		zombie.push(126);
		zombie.push(84);
		zombie.push(42);

		for (MutantStack<int>::iterator it = zombie.begin(); it != zombie.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << BGREEN << "Stack size : " << zombie.size() << RESET << std::endl;
		if (!zombie.empty())
			std::cout << BYELLOW << "Top : " << zombie.top() << RESET << std::endl;

		zombie.pop();
		for (MutantStack<int>::iterator it = zombie.begin(); it != zombie.end(); ++it)
			std::cout << *it << std::endl;
		if (!zombie.empty())
			std::cout << BYELLOW << "Top (after pop) : " << zombie.top() << RESET << std::endl;
		while(!zombie.empty()) {
			std::cout << BPURPLE << "Once you pop you can't stop" << RESET << std::endl;
			zombie.safePop();
		}
		std::cout << BYELLOW << "Top : " << zombie.safeTop() << RESET << std::endl;
	}
	/* === TEST 3 === */
	{
		std::cout << BYELLOW << ">>>> Test #3 string, list, copy constructor" << RESET << std::endl;
		MutantStack<std::string, std::list<std::string> >	zombie_2;

		zombie_2.push("Hello");
		zombie_2.push("World");
		MutantStack<std::string, std::list<std::string> >	zombie(zombie_2);
		for (MutantStack<std::string, std::list<std::string> >::iterator it = zombie.begin(); it != zombie.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << BGREEN << "Stack size : " << zombie.size() << RESET << std::endl;
		while(!zombie.empty()) {
			std::cout << BPURPLE << "Once you pop you can't stop" << RESET << std::endl;
			zombie.safePop();
		}
		zombie.safePop();
		std::cout << BGREEN << "Stack size : " << zombie.size() << RESET << std::endl;

	}
	return 0;
}
