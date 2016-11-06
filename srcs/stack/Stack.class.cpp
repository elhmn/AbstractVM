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
