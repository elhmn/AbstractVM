/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:45:35 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/17 17:33:58 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <error.h>
#include <lexer.hpp>
#include <list>
#include <vector>
#include <regex>

static void				get_token(t_tok_tab *toks,
						std::string line)
{
// 	I am just testing
	std::regex			pattern(";;");
	std::smatch			match;
	std::string			tmp;

// 	std::list<t_tok>	tks = new std::list<t_tok>();

	if (!toks)
		ERROR("toks");
// 	if (!tks)
// 		ERROR("tks");
	tmp = line;
	while (std::regex_search(tmp, match, pattern))
	{
		std::cout << "MATCH : " << match.str() << std::endl;
		tmp = match.suffix().str();
	}
// 	toks.add(tks);
// 	std::cout << line << std::endl;
}

t_tok_tab				*lexer(std::string filepath)
{
	std::ifstream		file;
	std::string			line;
	t_tok_tab			*toks;

	toks = NULL;
	std::cout << "I lex file" << std::endl;//_DEBUG_//
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
// You must not delete toks before this function return
// Implement an elaborate delete toks function that will be used instead of
// the basic delete(toks) function call
			delete(toks);
		}
	}
	catch (const std::ifstream::failure& e)
	{
		ERROR("Exception opening/reading/closing file");
	}
	return (toks);
}
