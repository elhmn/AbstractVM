/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limit.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 19:02:17 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/30 18:21:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lexer.hpp"
#include "vm_types.hpp"
#include "Operand.class.hpp"
#include "Excep.class.hpp"

static eOperandType		typeTab[5] = {Int8, Int16, Int32, Float, Double};
static double			limMax[5] = {INT8_MAX, INT16_MAX,
										INT32_MAX, FLT_MAX, DBL_MAX};
static double			limMin[5] = {INT8_MIN, INT16_MIN,
										INT32_MIN, -FLT_MAX, -DBL_MAX};
static std::string		opTab[5] = {K_ADD, K_SUB, K_MUL, K_DIV, K_MOD};


/*
** Over flow functions
*/

static bool				over_add(t_double a, t_double b, int i)
{
	return ((b > 0) ? a > limMax[i] - b : false);
}

static bool				over_sub(t_double a, t_double b, int i)
{
	return ((b < 0) ? a > limMax[i] + b : false);
}

static bool				over_mul(t_double a, t_double b, int i)
{
	if ((a > 0 && b > 0)
			|| (a < 0 && b < 0))
	{
		if (ABS(b) > 1)
		{
			if (b < 0)
				return (a < limMax[i] / b);
			return (a > limMax[i] / b);
		}
	}
	return (false);
}

static bool				over_div(t_double a, t_double b, int i)
{
	if ((a > 0 && b > 0)
			|| (a < 0 && b < 0))
	{
		if (ABS(b) < 1)
		{
			if (b < 0)
				return (a < limMax[i] * b);
			return (a > limMax[i] * b);
		}
	}
	return (false);
}

// 	a % b underflow always false
static bool				over_mod(t_double a, t_double b, int i)
{
	(void)a;
	(void)b;
	(void)i;
	return (false);
}

/*
** under flow functions
*/

static bool				under_add(t_double a, t_double b, int i)
{
	return ((b > 0) ? a < limMin[i] - b : false);
}

static bool				under_sub(t_double a, t_double b, int i)
{
	return ((b < 0) ? a < limMin[i] + b : false);
}

static bool				under_mul(t_double a, t_double b, int i)
{
	if ((a > 0 && b < 0)
			|| (a < 0 && b > 0))
	{
		if (ABS(b) > 1)
		{
			if (b < 0)
				return (a > limMin[i] / b);
			return (a < limMin[i] / b);
		}
	}
	return (false);
}

static bool				under_div(t_double a, t_double b, int i)
{
	if ((a > 0 && b < 0)
			|| (a < 0 && b > 0))
	{
		if (ABS(b) < 1)
		{
			if (b < 0)
				return (a > limMin[i] * b);
			return (a < limMin[i] * b);
		}
	}
	return (false);
}

// 	a % b underflow always false
static bool				under_mod(t_double a, t_double b, int i)
{
	(void)a;
	(void)b;
	(void)i;
	return (false);
}

typedef  bool			(*t_lim_f)(t_double a, t_double b, int i);

static t_lim_f			overTab[5] = {
											over_add,
											over_sub,
											over_mul,
											over_div,
											over_mod
									};

static t_lim_f			underTab[5] = {
											under_add,
											under_sub,
											under_mul,
											under_div,
											under_mod
									};


void		check_op_overflow(std::string op,
								eOperandType type, t_double a, t_double b)
{
	for (int i = 0; i < 5; i++)
	{
		if (typeTab[i] == type)
		{
			for (int j = 0; j < 5; j++)
			{
				if (op == opTab[j]
						&& overTab[j](a, b, i))
					throw E_OVERFLOW;
			}
		}
	}
}

void		check_op_underflow(std::string op,
								eOperandType type, t_double a, t_double b)
{
	for (int i = 0; i < 5; i++)
	{
		if (typeTab[i] == type)
		{
			for (int j = 0; j < 5; j++)
			{
				if (op == opTab[j]
						&& underTab[j](a, b, i))
					throw E_UNDERFLOW;
			}
		}
	}
}

void		check_overflow(eOperandType type, t_double a)
{
	for (int i = 0; i < 5; i++)
	{
		if (typeTab[i] == type)
		{
			if (a > limMax[i])
				throw E_OVERFLOW;
		}
	}
}

void		check_underflow(eOperandType type, t_double a)
{
	for (int i = 0; i < 5; i++)
	{
		if (typeTab[i] == type)
		{
			if (a < limMin[i])
				throw E_UNDERFLOW;
		}
	}
}

t_double		check_limits(eOperandType type, t_double a)
{
	check_overflow(type, a);
	check_underflow(type, a);
	return (a);
}
