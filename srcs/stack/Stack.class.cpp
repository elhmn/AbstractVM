#include "Stack.class.hpp"
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
void		Stack::push(IOperand const *o)
{
	if (!this->_stack)
	{
		this->_stack = new std::stack<IOperand const *>();
		if (!this->_stack)
		{
			std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
			exit(0);
		}
	}
	if (!o)
	{
		//normally maybe you must throw an exception
		std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
		exit(0);
	}
	this->_stack->push(o);
}

void	Stack::dump(void) const
{
	std::stack<IOperand const *>	tmp;

	if (!this->_stack)
	{
		std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
		exit(0);
	}
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
	if (!this->_stack)
	{
		std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
		exit(0);
	}
	if (this->_stack->empty())
	{
		//here throw the exception
		std::cout << "can't pop on an empty stack" << std::endl;
		exit(0);
	}
	delete this->_stack->top();
	this->_stack->pop();
}

void	Stack::add(void)
{
	std::cout <<  "I add" << std::endl;
}

void	Stack::sub(void)
{
	std::cout <<  "I sub" << std::endl;
}

void	Stack::mul(void)
{
	std::cout <<  "I mul" << std::endl;
}

void	Stack::div(void)
{
	std::cout <<  "I div" << std::endl;
}

void	Stack::mod(void)
{
	std::cout <<  "I mod" << std::endl;
}
