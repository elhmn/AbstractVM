/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:47:33 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/19 22:40:33 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "exec.hpp"
#include "error.h"
#include "Vm.class.hpp"
#include "Factory.class.hpp"

static eOperandType			getOperandType(std::string sType)
{
	if (sType == K_INT8)
		return (Int8);
	else if (sType == K_INT16)
		return (Int16);
	else if (sType == K_INT32)
		return (Int32);
	else if (sType == K_FLOAT)
		return (Float);
	else if (sType == K_DOUBLE)
		return (Double);
	ERROR("Unknown eOperand type");
	return (Double);
}

int						exec(t_tok_tab **toks)
{
	Vm									*vm;
	Stack								*st;
	Factory								*fc;
	std::list<t_tok*>					l;
	std::list<t_tok*>::const_iterator	lt;
	std::string							vTab[3];

	if (!toks || !*toks)
		ERROR("toks");
	if (!(vm = Vm::getInstance()))
		ERROR("vm");
	if (!(st = vm->getStack()))
		ERROR("st");
	if (!(fc = Factory::getInstance()))
		ERROR("fc");
	for (t_tok_tab::const_iterator it = (**toks).begin(); it != (**toks).end(); it++)
	{
		l = **it;
		lt = l.begin();
		vTab[0] = (*lt)->val;
// 		std::cout << vTab[0]; //_DEBUG_//
		if (l.size() ==  3)
		{
			vTab[1] = (*(++lt))->val;
			vTab[2] = (*(++lt))->val;
			if (vTab[0] == K_PUSH)
				st->push(fc->createOperand(getOperandType(vTab[1]), vTab[2]));
			//free value after assertion
			else if (vTab[0] == K_ASSERT)
				st->assert(fc->createOperand(getOperandType(vTab[1]), vTab[2]));
			//push assert
// 			std::cout << " " << vTab[1] << " " << vTab[2];//_DEBUG_//
		}
		else
		{
			if (vTab[0] == K_POP)
				st->pop();
			else if (vTab[0] == K_DUMP)
				st->dump();
			else if (vTab[0] == K_ADD)
				st->add();
			else if (vTab[0] == K_SUB)
				st->sub();
			else if (vTab[0] == K_MUL)
				st->mul();
			else if (vTab[0] == K_DIV)
				st->div();
			else if (vTab[0] == K_MOD)
				st->mod();
			else if (vTab[0] == K_PRINT)
				st->print();
			else if (vTab[0] == K_EXIT)
				vm->vm_exit();
		}
		std::cout << std::endl;//_DEBUG_//
	}

// 	std::cout << "I Dump : " << std::endl;//_DEBUG_//
// 	st->dump();//_DEBUG_//
	return (0);
}
