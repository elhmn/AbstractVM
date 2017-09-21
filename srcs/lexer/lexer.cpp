/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:45:35 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/19 20:53:17 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <error.h>
#include <list>
#include <vector>
#include <regex>
#include "lexer.hpp"
#include "Excep.class.hpp"

static t_tok			*new_tok(std::string val, e_tok type)
{
	t_tok		*tok;

	if (!(tok = new t_tok()))
		ERROR("tok");
	tok->type = type;
	tok->val = val;
	return (tok);
}

static int				get_token(t_tok_tab *toks,
						std::string line)
{
	std::list<t_tok*>	*tok_l;
	t_tok				*tok;
	std::regex			p_empty(RGX_START RGX_END);
	std::regex			p_line(RGX_LINE);
	std::regex			p_line_val(RGX_LINE_VAL);
	std::smatch			match;

	tok = NULL;
	if (!toks)
		ERROR("toks");
	if (line == RGX_ENDINSTR)
		return (-1);
	if (std::regex_match(line, match, p_empty,
			std::regex_constants::match_default))
		return (0);
	if (!(tok_l = new std::list<t_tok*>()))
		ERROR("tok_l");
	if (std::regex_match(line, match, p_line,
			std::regex_constants::match_default))
		tok_l->push_back(new_tok(match[1].str(), INSTR));
	else if (std::regex_match(line, match, p_line_val,
				std::regex_constants::match_default))
	{
		tok_l->push_back(new_tok(match[1].str(), INSTR));
		if (!match[4].str().empty())
		{
			tok_l->push_back(new_tok(match[4].str(), VALTYPE));
			tok_l->push_back(new_tok(match[5].str(), VALUE));
		}
		else
		{
			tok_l->push_back(new_tok(match[7].str(), VALTYPE));
			tok_l->push_back(new_tok(match[8].str(), VALUE));
		}
	}
	else
	{
		delete (tok_l);
		throw E_LEXICAL(line.c_str());
		return (0);
	}
	toks->push_back(tok_l);
	return (0);
}

//Read from file
int			lexer(t_tok_tab **toks, std::string filepath)
{
	std::ifstream		file;
	std::string			line;

	file.exceptions(std::ifstream::badbit);
	try
	{
		file.open(filepath);
		if (file.is_open())
		{
			if (!(*toks = new std::vector< std::list<t_tok*>* >()))
				ERROR("toks");
			while (std::getline(file, line))
			{
				if (get_token(*toks, line) == -1)
					break ;
			}
			file.close();
		}
	}
	catch (const std::ifstream::failure& e)
	{
		ERROR("Exception opening/reading/closing file");
	}
	return (0);
}

//read from standard input
int			lexer(t_tok_tab **toks)
{
	std::string			line;

	try
	{
		if (!(*toks = new std::vector< std::list<t_tok*>* >()))
			ERROR("toks");
		while (std::getline(std::cin, line))
		{
			if (get_token(*toks, line) == -1)
				break ;
		}
	}
	catch (const std::ifstream::failure& e)
	{
		ERROR("Exception opening/reading/closing standard input");
	}
	return (0);
}
