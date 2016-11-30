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
void		Stack::assert(IOperand const *o) const
{
// 	check if o type and value are equal to Operand at the top of the Stack
	(void)o;
	std::cout << "I assert something" << std::endl;
}

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

void	Stack::print(void) const
{
	std::cout << "I assert" << std::endl;
	//assert that the value at the top of the stack is an 8-bit integer
	//then display the corresponding ascii character to the output
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
	IOperand const *a;
	IOperand const *b;

	a = NULL;
	b = NULL;
	if (!this->_stack)
	{
		std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
		exit(0);
	}
	if (this->_stack->size() < 2)
	{
		//here throw the appropriate exception
		std::cout << "can't add less than two values" << std::endl;
		exit(0);
	}
	a = this->_stack->top();
	this->_stack->pop();
	b = this->_stack->top();
	this->_stack->pop();
	this->push(*b + *a);
	std::cout << "add those value then" << std::endl;//_DEBUG_//
// 	std::cout <<  "I add" << std::endl;//_DEBUG_//
}

void	Stack::sub(void)
{
	IOperand const *a;
	IOperand const *b;

	a = NULL;
	b = NULL;
	if (!this->_stack)
	{
		std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
		exit(0);
	}
	if (this->_stack->size() < 2)
	{
		//here throw the appropriate exception
		std::cout << "can't sub less than two values" << std::endl;
		exit(0);
	}
	a = this->_stack->top();
	this->_stack->pop();
	b = this->_stack->top();
	this->_stack->pop();
	this->push(*b - *a);
	std::cout <<  "I sub" << std::endl;
}

void	Stack::mul(void)
{
	IOperand const *a;
	IOperand const *b;

	a = NULL;
	b = NULL;
	if (!this->_stack)
	{
		std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
		exit(0);
	}
	if (this->_stack->size() < 2)
	{
		//here throw the appropriate exception
		std::cout << "can't mult less than two values" << std::endl;
		exit(0);
	}
	a = this->_stack->top();
	this->_stack->pop();
	b = this->_stack->top();
	this->_stack->pop();
	this->push(*b * *a);
	std::cout <<  "I mul" << std::endl;
}

void	Stack::div(void)
{
	IOperand const *a;
	IOperand const *b;

	a = NULL;
	b = NULL;
	if (!this->_stack)
	{
		std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
		exit(0);
	}
	if (this->_stack->size() < 2)
	{
		//here throw the appropriate exception
		std::cout << "can't div less than two values" << std::endl;
		exit(0);
	}
	a = this->_stack->top();
	this->_stack->pop();
	b = this->_stack->top();
	this->_stack->pop();
	// don't forget to throw the div by zero exception
	this->push(*b / *a);
	std::cout <<  "I div" << std::endl;
}

void	Stack::mod(void)
{
	IOperand const *a;
	IOperand const *b;

	a = NULL;
	b = NULL;
	if (!this->_stack)
	{
		std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
		exit(0);
	}
	if (this->_stack->size() < 2)
	{
		//here throw the appropriate exception
		std::cout << "can't mod less than two values" << std::endl;
		exit(0);
	}
	a = this->_stack->top();
	this->_stack->pop();
	b = this->_stack->top();
	this->_stack->pop();
	// don't forget to throw the mod by zero exception
	// and check also whether operand types is float or fouble
	this->push(*b % *a);
	std::cout <<  "I mod" << std::endl;
}
