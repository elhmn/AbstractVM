/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:47:33 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/24 14:55:26 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "exec.hpp"
#include "parser.hpp"
#include "error.h"
#include "Vm.class.hpp"
#include "Factory.class.hpp"
#include "Excep.class.hpp"

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

static void				initExec(t_tok_tab **toks, Vm **v, Stack **s)
{
	if (!toks || !*toks)
		ERROR("toks");
	if (!(*v = Vm::getInstance()))
		ERROR("vm");
	if (!(*s = v[0]->getStack()))
		ERROR("st");
}

static void				execComplexCommand(Stack *st, std::string c,
							std::string opType, std::string opVal)
{
	Factory								*fc;

	if (!st)
		ERROR("st");
	if (!(fc = Factory::getInstance()))
		ERROR("fc");
	if (c == K_PUSH)
		st->push(fc->createOperand(getOperandType(opType), opVal));
	//free value after assertion
	else if (c == K_ASSERT)
		st->assert(fc->createOperand(getOperandType(opType), opVal));
}


static void				execSimpleCommand(t_tok_tab **t, Stack *st, Vm *vm, std::string c)
{
	if (!st)
		ERROR("st");
	if (c == K_POP)
		st->pop();
	else if (c == K_DUMP)
		st->dump();
	else if (c == K_ADD)
		st->add();
	else if (c == K_SUB)
		st->sub();
	else if (c == K_MUL)
		st->mul();
	else if (c == K_DIV)
		st->div();
	else if (c == K_MOD)
		st->mod();
	else if (c == K_PRINT)
		st->print();
	else if (c == K_EXIT)
	{
		clear_tok_tab(t);
		vm->vm_exit();
	}
}

int						exec(t_tok_tab **toks)
{
	Vm									*vm;
	Stack								*st;
	std::list<t_tok*>					l;
	std::list<t_tok*>::const_iterator	lt;
	std::string							vTab[3];

	initExec(toks, &vm, &st);
	for (t_tok_tab::const_iterator it = (**toks).begin(); it != (**toks).end(); it++)
	{
		l = **it;
		lt = l.begin();
		vTab[0] = (*lt)->val;
		if (l.size() ==  3)
		{
			vTab[1] = (*(++lt))->val;
			vTab[2] = (*(++lt))->val;
			execComplexCommand(st, vTab[0], vTab[1], vTab[2]);
		}
		else
			execSimpleCommand(toks, st, vm, vTab[0]);
	}
	throw E_NOEXIT;
	return (0);
}
