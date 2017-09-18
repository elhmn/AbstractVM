/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:59:05 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/18 18:19:04 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.hpp"

void			put_tok(t_tok t)
{
	std::cout << "type : [" << t.type << "]"	\
				<< " | val : [" << t.val		\
				<< "]";
}

void			put_tok_list(std::list<t_tok> l)
{
	std::cout << "List : " << std::endl;
	std::cout << "{" << std::endl;
	for (std::list<t_tok>::const_iterator it = l.begin(); it != l.end(); ++it)
	{
		std::cout << "\t";
		put_tok(*it);
		std::cout << std::endl;
	}
	std::cout << "}" << std::endl;
}

void			put_tok_tab(t_tok_tab tab)
{
	std::cout << "Vector : " << std::endl;
	std::cout << "{" << std::endl;
	for (t_tok_tab::const_iterator it = tab.begin(); it != tab.end(); ++it)
	{
		std::cout << "--------------- LIST START -----------------" << std::endl;
		put_tok_list(*it);
		std::cout << "---------------- LIST END ------------------" << std::endl;
	}
	std::cout << "}" << std::endl;
}
