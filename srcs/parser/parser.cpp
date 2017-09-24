/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:46:22 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/24 14:29:04 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "parser.hpp"
#include "Excep.class.hpp"
#include "error.h"

int					parser(t_tok_tab **toks)
{
	bool					isExit;
	std::list<t_tok*>		l;

	isExit = false;
	if (!toks || !*toks)
		ERROR("toks");
	for (t_tok_tab::const_iterator it = (**toks).begin();
			it != (**toks).end(); it++)
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
		throw E_SYNTAX("missing exit instruction");
	return (0);
}
