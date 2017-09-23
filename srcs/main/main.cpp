/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 16:52:42 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/23 14:41:21 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vm.class.hpp"
#include "error.h"

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
	Vm	*vm;

	if (!(vm = Vm::getInstance()))
		ERROR("vm");
	if (ac == 1)
		vm->run("");
	else
		vm->run(av[1]);
	return (0);
}
