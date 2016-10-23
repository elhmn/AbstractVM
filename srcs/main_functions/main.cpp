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

#include <iostream>
#include <cstdint>

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac == 1)
		//Read from standard input
		std::cout << "I read from standard input" << std::endl; //Debug
	else
	{
		int8_t	i_8;
		int16_t	i_16;
		int32_t	i_32;

		i_8 = static_cast<int8_t>(8000); //Debug
		i_16 = static_cast<int16_t>(8000); //Debug
		i_32 = static_cast<int32_t>(8000); //Debug
		std::cout << "i_8 = [" << i_8 << "]" << std::endl; //Debug
		std::cout << "int8_max = [" << INT8_MAX << "]" << std::endl; //Debug
		std::cout << "int8_max = [" << INT8_MIN << "]" << std::endl; //Debug
		
		std::cout << "i_16 = [" << i_16 << "]" << std::endl; //Debug
		std::cout << "int16_max = [" << INT16_MAX << "]" << std::endl; //Debug
		std::cout << "int16_max = [" << INT16_MIN << "]" << std::endl; //Debug
		
		std::cout << "i_32 = [" << i_32 << "]" << std::endl; //Debug
		std::cout << "int32_max = [" << INT32_MAX << "]" << std::endl; //Debug
		std::cout << "int32_max = [" << INT32_MIN << "]" << std::endl; //Debug
	}
	return (0);
}
