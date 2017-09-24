/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_types.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 21:45:29 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/24 11:25:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_TYPES_HPP
# define VM_TYPES_HPP

# include <stdint.h>
# include <cfloat>

# define ABS(x) (x < 0) ? -x : x

typedef int8_t		t_int8;
typedef int16_t		t_int16;
typedef int32_t		t_int32;
typedef float		t_float;
typedef double		t_double;

enum				eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double,
};


/*
** exception/check_limit.cpp
*/

void		check_overflow(std::string op,
				eOperandType type, t_double a, t_double b);

void		check_downflow(std::string op,
				eOperandType type, t_double a, t_double b);

#endif
