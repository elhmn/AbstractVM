/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:45:35 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/12 17:29:40 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <error.h>
#include <lexer.hpp>
#include <list>
#include <vector>

static void				get_token(t_tok_tab *toks,
						std::string line)
{
	(void)toks;
	(void)line;

	if (!toks)
		ERROR("toks");
	std::cout << line << std::endl;
}

t_tok_tab				*lexer(std::string filepath)
{
	std::ifstream		file;
	std::string			line;
	t_tok_tab			*toks;

	toks = NULL;
	std::cout << "i lex file" << std::endl;//_DEBUG_//
	file.exceptions(std::ifstream::badbit);
	try
	{
		file.open(filepath);
		if (file.is_open())
		{
			if (!(toks = new std::vector< std::list<t_tok> >()))
				ERROR("toks");
			while (std::getline(file, line))
			{
				get_token(toks, line);
// 				lexe file
			}
			file.close();
		}
	}
	catch (const std::ifstream::failure& e)
	{
		ERROR("Exception opening/reading/closing file");
	}
	return (toks);
}
