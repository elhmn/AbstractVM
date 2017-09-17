/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:45:35 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/17 19:57:29 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <error.h>
#include <lexer.hpp>
#include <list>
#include <vector>
#include <regex>

static int				get_token(t_tok_tab *toks,
						std::string line)
{
// 	I am just testing
	std::regex			p_comment(RGX_COMMENT);
	std::regex			p_line(RGX_LINE_VAL);
// 	std::regex			p_line_val(RGX_LINE_VAL);
	std::smatch			match;
	std::string			tmp;

// 	std::list<t_tok>	tks = new std::list<t_tok>();

	if (!toks)
		ERROR("toks");
// 	if (!tks)
// 		ERROR("tks");
	if (line == RGX_ENDINSTR)
	{
		std::cout << "end of script" << std::endl;//_DEBUG_//
		return (-1);
	}
	tmp = line;
// 	std::cout << "LINE : [" << tmp << "]" << std::endl;//_DEBUG_//
// 	std::cout << "REGEX COMMENT: #" << RGX_COMMENT << "#" << std::endl;//_DEBUG_//
	if (std::regex_match(tmp, match, p_comment, std::regex_constants::match_default))
	{
		for (int i = 0; i < (int)match.size(); i++)
			std::cout << "MATCH[" << i<< "] : [" << match[i].str() << "]" << std::endl;//_DEBUG_//
		tmp = match.suffix().str();
	}
	tmp = line;
	std::cout << "LINE : [" << tmp << "]" << std::endl;//_DEBUG_//
	std::cout << "REGEX LINE: #" << RGX_LINE_VAL << "#" << std::endl;//_DEBUG_//
	if (std::regex_match(tmp, match, p_line, std::regex_constants::match_default))
	{
		for (int i = 0; i < (int)match.size(); i++)
			std::cout << "MATCH[" << i<< "] : [" << match[i].str() << "]" << std::endl;//_DEBUG_//
		tmp = match.suffix().str();
	}
// 	toks.add(tks);
// 	std::cout << line << std::endl;
	return (0);
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
				if (get_token(toks, line) == -1)
					return (toks);
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
