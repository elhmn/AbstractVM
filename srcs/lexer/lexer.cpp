/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:45:35 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/18 18:46:30 by bmbarga          ###   ########.fr       */
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
	std::regex			p_empty(RGX_START RGX_END);
	std::regex			p_line(RGX_LINE);
	std::regex			p_line_val(RGX_LINE_VAL);
	std::smatch			match;
	std::list<t_tok>	tks;
	t_tok				*tok;

	tok = NULL;
	if (!toks)
		ERROR("toks");
// 	if (!tks)
// 		ERROR("tks");
// 		for (int i = 0; i < (int)match.size(); i++)
// 			std::cout << "MATCH[" << i << "] : [" << match[i].str() << "]" << std::endl;//_DEBUG_//
	if (line == RGX_ENDINSTR)
	{
		std::cout << "end of script" << std::endl;//_DEBUG_//
		return (-1);
	}
	if (std::regex_match(line, match, p_line, std::regex_constants::match_default))
	{
		std::cout << "MATCH[" << 1 << "] : [" << match[1].str() << "]" << std::endl;//_DEBUG_//
// 		match[1] instruction
	}
	else if (std::regex_match(line, match, p_line_val, std::regex_constants::match_default))
	{
		std::cout << "MATCH[" << 1 << "] : [" << match[1].str() << "]" << std::endl;//_DEBUG_//
		std::cout << "MATCH[" << 4 << "] : [" << match[4].str() << "]" << std::endl;//_DEBUG_//
		std::cout << "MATCH[" << 5 << "] : [" << match[5].str() << "]" << std::endl;//_DEBUG_//
		std::cout << "MATCH[" << 7 << "] : [" << match[7].str() << "]" << std::endl;//_DEBUG_//
		std::cout << "MATCH[" << 8 << "] : [" << match[8].str() << "]" << std::endl;//_DEBUG_//
// 		need line , value type, and type
// 		types are stored in match[4] for integers and match[7] for floating points (double && float)
// 		values are stored in match[5] for integers and match[8] for floating points (double && float)
	}
	else if (std::regex_match(line, match, p_empty, std::regex_constants::match_default))
	{
 		std::cout << "empty or commented line : " << std::endl;//_DEBUG_//
		std::cout << "LINE : [" << line << "]" << std::endl;//_DEBUG_//
	}
	else
	{
		std::cout << "UNKNOWN line :: ##############################" << std::endl;//_DEBUG_//
		std::cout << "LINE : [" << line << "]" << std::endl;//_DEBUG_//
		std::cout << "UNKNOWN line END :: ##############################" << std::endl;//_DEBUG_//
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
