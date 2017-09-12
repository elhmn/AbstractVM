/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:19:36 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/12 17:24:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <vector>
# include <list>

enum			e_tok
{
	UNKNOWN,
	KEYWORD,
	COMMENT,
	INTERGER,
	FLOAT
};

typedef struct	s_tok
{
	e_tok		type;
	char		*val;
}				t_tok;

typedef std::vector< std::list<t_tok> >		t_tok_tab;

/*
** lexer/lexer.cpp
*/

t_tok_tab									*lexer(std::string filepath);

#endif
