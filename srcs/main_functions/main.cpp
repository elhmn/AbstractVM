/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 16:52:42 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/23 13:49:52 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include "IOperand.class.hpp"
#include "Operand.class.hpp"
#include "Vm.class.hpp"

/*
** TODO
**	- FILE READER
**	- LEXER
**	- PARSER
**	- EXEC
**	- OTHER stuff requiered to run the program
*/

void	test(void);

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac == 1)
		std::cout << "I read from standard input" << std::endl;//_DEBUG_//
	else
	{
		std::cout << "I read from file" << std::endl;//_DEBUG_//
		Vm * vm = Vm::getInstance();//_DEBUG_//
		(void)vm;//_DEBUG_//
		test();//_DEBUG_//
		Operand<t_int8>		o(Int8, 10);
		Operand<t_int16>	e(Int16, 100);
		Operand<t_int32>	i(Int32, 100);
		Operand<t_double>	d(Double, 100.3);
		Operand<t_float>	f(Float, 100.98);
// 		Operand<t_float>	g(Float, 10);
		IOperand const		*g;

		g = o + e; //int8
		(void)g;
// 		g = e + o; //int16
// 		g = e + i; //int16
// 		g = e + d; //Double
// 		g = e + f; //Float
		std::cout << "-----------------------" << std::endl;
		o / e; //int8
		e / o; //int16
		e / i; //int16
		e / d; //Double
		e / f; //Float
		std::cout << "-----------------------" << std::endl;
		o % e; //int8
		e % o; //int16
		e % i; //int16
		e % d; //Double
		e % f; //Float
		std::cout << "-----------------------" << std::endl;
		o - e; //int8
		e - o; //int16
		e - i; //int16
		e - d; //Double
		e - f; //Float
		std::cout << "-----------------------" << std::endl;
		o * e; //int8
		e * o; //int16
		e * i; //int16
		e * d; //Double
		e * f; //Float
	}
	return (0);
}
