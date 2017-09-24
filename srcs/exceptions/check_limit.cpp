/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limit.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 19:02:17 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/24 11:57:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lexer.hpp"
#include "vm_types.hpp"
#include "Operand.class.hpp"
#include "Excep.class.hpp"

static eOperandType		typeTab[5] = {Int8, Int16, Int32, Float, Double};
static double			limMax[5] = {INT8_MAX, INT16_MAX, INT32_MAX, FLT_MAX, DBL_MAX};
static double			limMin[5] = {INT8_MIN, INT16_MIN, INT32_MIN, FLT_MIN, DBL_MIN};
static std::string		opTab[5] = {K_ADD, K_SUB, K_MUL, K_DIV, K_MOD};


/*
** Over flow functions
*/

static bool				over_add(t_double a, t_double b, int i)
{
	return (a > limMax[i] - b);
}

static bool				over_sub(t_double a, t_double b, int i)
{
	return (a > limMax[i] + b);
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

// 	a % b downflow always false
static bool				over_mod(t_double a, t_double b, int i)
{
	(void)a;
	(void)b;
	(void)i;
	return (false);
}

/*
** Down flow functions
*/

// a + b < limMin[i]
static bool				down_add(t_double a, t_double b, int i)
{
	return (a < limMin[i] - b);
}

static bool				down_sub(t_double a, t_double b, int i)
{
	return (a < limMin[i] + b);
}

static bool				down_mul(t_double a, t_double b, int i)
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

static bool				down_div(t_double a, t_double b, int i)
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

// 	a % b downflow always false
static bool				down_mod(t_double a, t_double b, int i)
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

static t_lim_f			downTab[5] = {
											down_add,
											down_sub,
											down_mul,
											down_div,
											down_mod
									};


void		check_overflow(std::string op, eOperandType type, t_double a, t_double b)
{
	std::cout << "type = " << type << " | a = [" << a << "] | b = [" << b << " ]"<< std::endl;//_DEBUG_//
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
// 		std::cout << "limMax[" << i << "] - " << b << " =  "<< limMax[i] - b << std::endl;//_DEBUG_//
// 		std::cout << "limMax[" << i << "] = " << limMax[i] << std::endl;//_DEBUG_//
// 		std::cout << "typeTab[" << i << "] = " << typeTab[i] << std::endl;//_DEBUG_//
	}
}

void		check_downflow(std::string op, eOperandType type, t_double a, t_double b)
{
	std::cout << "type = " << type << " | a = [" << a << "] | b = [" << b << " ]"<< std::endl;//_DEBUG_//
	for (int i = 0; i < 5; i++)
	{
		if (typeTab[i] == type)
		{
			for (int j = 0; j < 5; j++)
			{
				if (op == opTab[j]
						&& downTab[j](a, b, i))
					throw E_DOWNFLOW;
			}
		}
// 		std::cout << "limMax[" << i << "] - " << b << " =  "<< limMax[i] - b << std::endl;//_DEBUG_//
// 		std::cout << "limMax[" << i << "] = " << limMax[i] << std::endl;//_DEBUG_//
// 		std::cout << "typeTab[" << i << "] = " << typeTab[i] << std::endl;//_DEBUG_//
	}
}
