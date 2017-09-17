/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 16:52:42 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/17 16:03:36 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vm.class.hpp"

/*
** TODO
**	- FILE READER
**	- LEXER
**	- PARSER
**	- EXEC
**	- OTHER stuff required to run the program
**	Don't forget :
**		-Handle every error type with exceptions
**		-Build a Factory class to create Operands
**
**
**	ALSO Implement underflow and overflow exceptions
**		-Replace some Errors with exceptions
*/

int		main(int ac, char **av)
{
	Vm	*vm = NULL;

	if (!(vm = Vm::getInstance()))
	{
		std::cout << "vm instantiation error" << std::endl;
		return (0);
	}
	if (ac == 1)
	{
		std::cout << "I read from standard input" << std::endl;//_DEBUG_//
		vm->run();
	}
	else
	{
		std::cout << "I read from file" << std::endl;//_DEBUG_//
		vm->run(av[1]);
	}
	return (0);
}
