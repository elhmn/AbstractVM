/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_types.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 21:45:29 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/12 13:39:46 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_TYPES_HPP
# define VM_TYPES_HPP

# include <stdint.h>

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
	Double
};

#endif
