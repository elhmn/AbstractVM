/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 16:52:42 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/24 15:59:49 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vm.class.hpp"
#include "error.h"

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
