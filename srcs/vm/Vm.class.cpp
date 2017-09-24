/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.class.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:35:33 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/24 10:05:34 by bmbarga          ###   ########.fr       */
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
#include "error.h"
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
	t_tok_tab			*toks;

	toks = NULL;
	this->start();
	if (!(this->_stack = new Stack()))
		ERROR("stack");
	lexer(&toks, path);
	try
	{
		parser(&toks);
	}
	catch (std::logic_error e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	try
	{
		exec(&toks);
	}
	catch (std::runtime_error e)
	{
		std::cout << "Error : Runtime : " << e.what() << std::endl;
	}
//	clear stack ()
// 	delete stack ()
// 	set stack to NULL
	this->stop();
}

//actions
void	Vm::vm_exit(void)
{
	//the program should quit properly
	//clear the stack before leaving
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
