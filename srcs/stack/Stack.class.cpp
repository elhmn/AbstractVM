/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:35:10 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/23 14:50:11 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.class.hpp"
#include "Operand.class.hpp"
#include "Excep.class.hpp"
#include "error.h"
#include <iostream>
#include <cstdlib>

// TODO:
//  - Don't forget to implement catch the required exceptions

bool	Stack::verbose = false;

//constructors
Stack::Stack(void): _stack(NULL)
{
	if (Stack::verbose)
		std::cout << "Stack constructor called" << std::endl;
}

//destructor
Stack::~Stack(void)
{
	if (Stack::verbose)
		std::cout << "Stack destructor called" << std::endl;
}

//getters
std::stack<IOperand const *> *Stack::getStack(void) const
{
	return (this->_stack);
}

//actions
void		Stack::assert(IOperand const *o) const
{
	IOperand const			*tmp;

	tmp = NULL;
	if (!o)
		ERROR("o");
	if (!this->_stack)
		throw E_ASSERT;
	tmp = this->_stack->top();
	if (!tmp || tmp->getType() != o->getType())
		throw E_ASSERT;
	if (o->toString() != tmp->toString())
		throw E_ASSERT;
}

void		Stack::push(IOperand const *o)
{
	if (!this->_stack)
	{
		this->_stack = new std::stack<IOperand const *>();
		if (!this->_stack)
			ERROR("stack");
	}
	if (!o)
		ERROR("o");
	this->_stack->push(o);
}

//assert that the value at the top of the stack is an 8-bit integer
//then display the corresponding ascii character to the output
void	Stack::print(void) const
{
	IOperand const *o;

	o = NULL;
	if (!this->_stack)
		return ;
	o = this->_stack->top();
	if (!o || o->getType() != Int8)
		throw E_ASSERT; 
	std::cout << castInt8(o)->getValue();
}

void	Stack::dump(void) const
{
	std::stack<IOperand const *>	tmp;

	if (!this->_stack)
		return ;
	//show and copy the stack
	while (!this->_stack->empty())
	{
		tmp.push(this->_stack->top());
		std::cout << this->_stack->top()->toString() << std::endl;
		this->_stack->pop();
	}
	//copy tmp to stack
	while (!tmp.empty())
	{
		this->_stack->push(tmp.top());
		tmp.pop();
	}
}

void	Stack::pop(void)
{
	if (!this->_stack
		|| this->_stack->empty())
		throw E_EMPTYSTACK;
	delete this->_stack->top();
	this->_stack->pop();
}

void	Stack::add(void)
{
	IOperand const	*a;
	IOperand const	*b;

	a = NULL;
	b = NULL;
	if (!this->_stack)
		ERROR("_stack");
	if (this->_stack->size() < 2)
		throw E_FEWOPERAND;
	a = this->_stack->top();
	this->_stack->pop();
	b = this->_stack->top();
	this->_stack->pop();
	this->push(*b + *a);
}

void	Stack::sub(void)
{
	IOperand const *a;
	IOperand const *b;

	a = NULL;
	b = NULL;
	if (!this->_stack)
		ERROR("_stack");
	if (this->_stack->size() < 2)
		throw E_FEWOPERAND;
	a = this->_stack->top();
	this->_stack->pop();
	b = this->_stack->top();
	this->_stack->pop();
	this->push(*b - *a);
}

void	Stack::mul(void)
{
	IOperand const *a;
	IOperand const *b;

	a = NULL;
	b = NULL;
	if (!this->_stack)
		ERROR("_stack");
	if (this->_stack->size() < 2)
		throw E_FEWOPERAND;
	a = this->_stack->top();
	this->_stack->pop();
	b = this->_stack->top();
	this->_stack->pop();
	this->push(*b * *a);
}

void	Stack::div(void)
{
	IOperand const *a;
	IOperand const *b;

	a = NULL;
	b = NULL;
	if (!this->_stack)
		ERROR("_stack");
	if (this->_stack->size() < 2)
		throw E_FEWOPERAND;
	a = this->_stack->top();
	this->_stack->pop();
	b = this->_stack->top();
	this->_stack->pop();
	// don't forget to throw the div by zero exception
	this->push(*b / *a);
}

void	Stack::mod(void)
{
	IOperand const *a;
	IOperand const *b;

	a = NULL;
	b = NULL;
	if (!this->_stack)
		ERROR("_stack");
	if (this->_stack->size() < 2)
		throw E_FEWOPERAND;
	a = this->_stack->top();
	this->_stack->pop();
	b = this->_stack->top();
	this->_stack->pop();
	// don't forget to throw the mod by zero exception
	// and check also whether operand types is float or fouble
	this->push(*b % *a);
}
