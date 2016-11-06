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
#include "Operand.class.hpp"//_DEBUG_//
#include "Vm.class.hpp"
#include <sstream>//_DEBUG_//

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
		std::stringstream	ss;

		ss << 10;
		std::cout << ss.str() << std::endl;
	}
	return (0);
}
