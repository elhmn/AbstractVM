/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:19:36 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/18 21:38:52 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include "token.hpp"

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

/*
** regex
*/

//Must be checked before anything else
# define RGX_OR				"|"

# define RGX_PSTART			"("

# define RGX_PEND			")"

# define RGX_ENDINSTR		";;"

# define RGX_N				"[-]?[0-9]+"

# define RGX_Z				"[-]?[0-9]+\\.[0-9]+"

//1 or Plus spaces
# define RGX_SEP_1P			"[[:space:]]+"

//0 or Plus spaces
# define RGX_SEP_0P			"[[:space:]]*"

# define RGX_COMMENT		"(;+.*$|$)"

# define RGX_START			"^[[:space:]]*"

# define RGX_END			"[[:space:]]*" RGX_COMMENT

# define RGX_INTEGER		RGX_PSTART \
								K_INT8 RGX_OR \
								K_INT16 RGX_OR \
								K_INT32 \
							RGX_PEND

# define RGX_FLOATING		RGX_PSTART \
								K_FLOAT RGX_OR \
								K_DOUBLE \
							RGX_PEND

# define RGX_VAL			RGX_PSTART \
								K_INT8 RGX_OR \
								K_INT16 RGX_OR \
								K_INT32 RGX_OR \
								K_FLOAT RGX_OR \
								K_DOUBLE \
							RGX_PEND

# define RGX_INSTR			RGX_PSTART \
								K_POP RGX_OR \
								K_DUMP RGX_OR \
								K_ADD RGX_OR \
								K_SUB RGX_OR \
								K_MUL RGX_OR \
								K_DIV RGX_OR \
								K_MOD RGX_OR \
								K_PRINT RGX_OR \
								K_EXIT \
							RGX_PEND

# define RGX_INSTR_VAL		RGX_PSTART \
								K_PUSH RGX_OR \
								K_ASSERT \
							RGX_PEND

# define RGX_LINE			RGX_START RGX_INSTR RGX_END

# define RGX_LINE_VAL		RGX_START \
								RGX_INSTR_VAL \
								RGX_SEP_1P \
								RGX_PSTART \
									RGX_PSTART \
										RGX_INTEGER \
										RGX_SEP_0P \
										"\\(" RGX_SEP_0P \
											RGX_PSTART \
												RGX_N \
											RGX_PEND \
										RGX_SEP_0P "\\)" \
									RGX_PEND \
								RGX_OR \
									RGX_PSTART \
										RGX_FLOATING \
										RGX_SEP_0P \
										"\\(" RGX_SEP_0P \
											RGX_PSTART \
												RGX_Z \
											RGX_PEND \
										RGX_SEP_0P "\\)" \
									RGX_PEND \
								RGX_PEND \
							RGX_END

/*
** lexer/lexer.cpp
*/

t_tok_tab						*lexer(std::string filepath);

#endif
