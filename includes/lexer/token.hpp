/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:26:41 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/18 18:19:10 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <iostream>
# include <vector>
# include <list>

enum				e_tok
{
	UNKNOWN,
	INSTR,
	VALTYPE,
	VALUE,
	COMMENT,
	INTERGER,
	FLOATING,
	END
};

typedef struct		s_tok
{
	e_tok			type;
	std::string		val;
}					t_tok;

typedef std::vector< std::list<t_tok> >		t_tok_tab;

/*
** token.cpp
*/

void			put_tok(t_tok t);
void			put_tok_list(std::list<t_tok> l);
void			put_tok_tab(t_tok_tab tab);

#endif
