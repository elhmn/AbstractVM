#include "error.h"
#include "vm_types.hpp"
#include "Operand.class.hpp"
#include "Excep.class.hpp"

static eOperandType		typeTab[5] = {Int8, Int16, Int32, Float, Double};
static double			limMax[5] = {INT8_MAX, INT16_MAX, INT32_MAX, FLT_MAX, DBL_MAX};
static std::string		opTab[5] = {K_ADD, K_SUB, K_MUL, K_DIV, K_MOD}

static bool				over_add()
{

}

static bool				over_sub()
{

}

static bool				over_mul()
{

}

static bool				over_div()
{

}

static bool				over_mod()
{

}

// static double		limMIN[5] = {INT8_MIN, INT16_MIN, INT32_MIN, FLT_MIN, DBL_MIN};

void		check_overflow(std:string op, eOperandType type, t_double a, t_double b)
{
	std::cout << "type = " << type << " | a = [" << a << "] | b = [" << b << " ]"<< std::endl;//_DEBUG_//
	for (int i = 0; i < 5; i++)
	{
		if (typeTab[i] == type)
		{
			if (a > limMax[i] - b)
				throw E_OVERFLOW;
		}
// 		std::cout << "limMax[" << i << "] - " << b << " =  "<< limMax[i] - b << std::endl;//_DEBUG_//
// 		std::cout << "limMax[" << i << "] = " << limMax[i] << std::endl;//_DEBUG_//
// 		std::cout << "typeTab[" << i << "] = " << typeTab[i] << std::endl;//_DEBUG_//
	}
}
