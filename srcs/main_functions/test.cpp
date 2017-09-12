/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:19:08 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/12 17:23:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <error.h>
#include <fstream>

int			main(int ac, char **av)
{
	std::ifstream	file;
	std::string		line;

	if (ac == 1)
	{
		std::cout << "je suis con !" << std::endl;
	}
	else
	{
		file.exceptions(std::ifstream::badbit);
		try
		{
			file.open(av[1]);
			if (file.is_open())
			{
				while (std::getline(file, line))
				{
					std::cout << line << std::endl;
				}
				file.close();
			}
		}
		catch (const std::ifstream::failure& e)
		{
			ERROR("Exception opening/reading/closing file");
		}
	}
	return (0);
}
