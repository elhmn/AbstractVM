/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.class.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:35:33 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/19 20:15:56 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Vm.class.hpp"
#include "Operand.class.hpp"
#include "Factory.class.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "exec.hpp"
#include <map>

bool	Vm::verbose = false;
Vm		*Vm::_firstInstance = NULL;

//constructors
Vm::Vm(void):_stack(NULL), _running(false)
{
	if (Vm::verbose)
		std::cout << "Vm constructor called" << std::endl;
}

//destructor
Vm::~Vm(void)
{
	if (Vm::verbose)
		std::cout << "Vm destructor called" << std::endl;
	if (Vm::_firstInstance)
		delete Vm::_firstInstance;
}

//getters
Vm		*Vm::getInstance(void)
{
	if (!Vm::_firstInstance)
	{
		if (!(Vm::_firstInstance = new Vm))
		{
			std::cout << "Error allocation -> file :" \
						<< __FILE__ << " line : " << __LINE__ << std::endl;
			return (NULL);
		}
	}
	return (Vm::_firstInstance);
}

Stack	*Vm::getStack(void) const
{
	return (this->_stack);
}

void	Vm::run(std::string path)
{
	t_tok_tab						*toks;

	toks = NULL;
	this->start();
	if (!(this->_stack = new Stack()))
	{
		std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
		exit(0);
	}
	lexer(&toks, path);
 	parser(&toks);
	exec(&toks);
//	clear stack ()
	this->stop();
	std::cout << "vm run from file" << std::endl;
}

void	Vm::run(void)
{
	t_tok_tab			*toks;

	toks = NULL;
	this->start();
 	while (!this->stopped()) //condition de reprise
 	{
		if (!(this->_stack = new Stack()))
		{
			std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
			exit(0);
		}
		lexer(&toks);
		parser(&toks);
		exec(&toks);
// 		this->_stack->push(new Operand<t_int8>(Int8, 23));
// 		this->_stack->push(new Operand<t_int8>(Int8, 0));
// 		try
// 		{
// 			this->_stack->div();
// 		}
// 		catch (DivExcep &e)
// 		{
// 			std::cout << "Error :: " << e.what() << std::endl;
// 		}
// 		std::cout << "dumped :: " << std::endl;
// 		this->_stack->push(Factory::getInstance()->createOperand(Int8, "-1"));
// 		this->_stack->push(Factory::getInstance()->createOperand(Int16, "-2"));
// 		this->_stack->push(Factory::getInstance()->createOperand(Int32, "-3"));
// 		this->_stack->push(Factory::getInstance()->createOperand(Float, "-4.8787"));
// 		this->_stack->push(Factory::getInstance()->createOperand(Double, "5"));
// 		this->_stack->dump();
// 		this->_stack->print();
// 		Read() from stdin
// 		Lexer()
// 		Parse()
// 		Exec()
// 		clear stack ()
// 		delete stack ()
// 		set stack to NULL
 		std::cout << "vm run" << std::endl;
		this->stop();
 	}
}

//actions
void	Vm::vm_exit(void)
{
	//the program should quit properly
	exit(0);
}

//check whether the vm is stopped or not
bool	Vm::stopped(void)
{
	return (!this->_running);
}

//start the vm
void	Vm::start(void)
{
	if (!this->_running)
		this->_running = true;
}

//stop the vm
void	Vm::stop(void)
{
	if (this->_running)
		this->_running = false;
}
