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

/*
** TODO
**	- FILE READER
**	- LEXER
**	- PARSER
**	- EXEC
**	- OTHER stuff requiered to run the program
*/

/*
** Note don't forget you used c++11 flags for <cstdint>
*/

#include <iostream>
#include "IOperand.class.hpp"

void	test(void);

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac == 1)
		//Read from standard input
		std::cout << "I read from standard input" << std::endl; //Debug
	else
		test();//Debug
	return (0);
}
