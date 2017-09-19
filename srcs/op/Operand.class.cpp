/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:35:14 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/19 23:01:10 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.class.hpp"

Operand<t_int8>	const *castInt8(const IOperand *op)
{
	return (dynamic_cast<Operand<t_int8> const *>(op));
}

Operand<t_int16> const	*castInt16(const IOperand *op)
{
	return (dynamic_cast<Operand<t_int16> const *>(op));
}

Operand<t_int32> const	*castInt32(const IOperand *op)
{
	return (dynamic_cast<Operand<t_int32> const *>(op));
}

Operand<t_float> const	*castFloat(const IOperand *op)
{
	return (dynamic_cast<Operand<t_float> const *>(op));
}

Operand<t_double> const *castDouble(const IOperand *op)
{
	return (dynamic_cast<Operand<t_double> const *>(op));
}
