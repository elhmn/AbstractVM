/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:46:22 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/19 18:10:45 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "parser.hpp"
#include "error.h"

// I stop executing at exit
//
// If there is no exit instruction in the file display an
// Warning
//
//
// The parser also removes every instruction folowing an exit before any execution
//
// Check syntax errors

int					parser(t_tok_tab **toks)
{
	bool					isExit;
	std::list<t_tok*>		l;

	isExit = false;
	if (!toks || !*toks)
		ERROR("toks");
	for (t_tok_tab::const_iterator it = (**toks).begin(); it != (**toks).end(); it++)
	{
		l = **it;
		if (!isExit && (**l.begin()).val == K_EXIT)
		{
			isExit = true;
			continue ;
		}
		if (isExit)
		{
			clear_partial_tab(*toks, it, (**toks).end());
			break ;
		}
	}
	if (!isExit)
		std::cout << "Error : missing exit instruction" << std::endl;
	return (0);
}
