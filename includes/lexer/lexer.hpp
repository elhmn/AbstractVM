/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:19:36 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/17 16:55:52 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <vector>
# include <list>

/*
** Useful strings
*/

# define S_COMA				";"
# define S_PARENTHESIS_O	"("
# define S_PARENTHESIS_C	")"
# define S_DOUBLECOMA		";;"
# define S_SEP				"\n"


/*
** Keywords : commands
*/

# define K_PUSH				"push"
# define K_POP				"pop"
# define K_DUMP				"dump"
# define K_ASSERT			"assert"
# define K_ADD				"add"
# define K_SUB				"sub"
# define K_MUL				"mul"
# define K_DIV				"div"
# define K_MOD				"mod"
# define K_PRINT			"print"
# define K_EXIT				"exit"

/*
** Keywords : values
*/

# define K_INT8				"int8"
# define K_INT16			"int16"
# define K_INT32			"int32"
# define K_FLOAT			"float"
# define K_DOUBLE			"double"

enum			e_tok
{
	UNKNOWN,
	INSTR,
	VALTYPE,
	VALUE,
	COMMENT,
	INTERGER,
	FLOAT,
	END
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
