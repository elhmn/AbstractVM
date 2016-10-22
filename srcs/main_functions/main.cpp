/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 16:52:42 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/22 17:43:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TODO
**	- FILE READER
**	- LEXER
**	- PARSER
**	- OTHER stuff requiered to run the program
*/

#include <iostream>

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac == 1)
		//Read from standard input
		std::cout << "I read from standard input" << std::endl; //Debug
	else
	{
		//Read data from file.avm
		while (42)
			std::cout << "je suis con" << std::endl;
	}
	return (0);
}
