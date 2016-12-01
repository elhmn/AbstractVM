#include "Vm.class.hpp"
#include "Operand.class.hpp"
#include <iostream>
#include <cstdlib>

bool	Vm::verbose = false;
Vm		*Vm::_firstInstance = NULL;

//constructors
Vm::Vm(void):_stack(NULL)
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

void	Vm::run(std::string path)
{
	(void)path;
	if (!(this->_stack = new Stack()))
	{
		std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
		exit(0);
	}
// 	Read() from path 
//	Lexer()
//	Parse()
//	Exec()
//	clear stack ()
	std::cout << "vm run from file" << std::endl;
}

void	Vm::run(void)
{
// 	while (42) //condition de reprise
// 	{
		if (!(this->_stack = new Stack()))
		{
			std::cout << "error :: " << "f->" << __FILE__ << " l->" << __LINE__ << std::endl;
			exit(0);
		}
//_DEBUG_//
		this->_stack->push(new Operand<t_int8>(Int8, 1));
		this->_stack->push(new Operand<t_int16>(Int16, 2));
		this->_stack->push(new Operand<t_int32>(Int32, 3));
		this->_stack->push(new Operand<t_double>(Double, 32.0));
		this->_stack->push(new Operand<t_float>(Float, 2.0));
		this->_stack->push(new Operand<t_int8>(Int8, 23));
		this->_stack->push(new Operand<t_int8>(Int8, 'j'));

		this->_stack->print(); //Debug
		this->_stack->assert(new Operand<t_int8>(Int8, 'j'));

		std::cout << "-------------------" << std::endl;//_DEBUG_//

		try
		{
// 			this->_stack->div();
			this->_stack->mod();
		}
		catch (DivExcep &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (ModExcep &e)
		{
			std::cout << e.what() << std::endl;
		}
		this->_stack->dump();

// 		this->_stack->dump();
// 		std::cout << "-------------------" << std::endl;
// 		this->_stack->pop();
// 		this->_stack->dump();
// 		std::cout << "-------------------" << std::endl;
// 		this->_stack->pop();
// 		this->_stack->dump();
// 		std::cout << "-------------------" << std::endl;
// 		this->_stack->pop();
// 		this->_stack->dump();
// 		std::cout << "-------------------" << std::endl;
// 		this->_stack->pop();
// 		this->_stack->dump();
// 		std::cout << "-------------------" << std::endl;
// 		this->_stack->pop();
// 		this->_stack->dump();

// 		std::cout << "-------------------" << std::endl;
// 		this->_stack->pop();
// 		this->_stack->dump();

//_DEBUG_//

// 		Read() from stdin
//		Lexer()
//		Parse()
//		Exec()
//		clear stack ()
//		delete stack ()
//		set stack to NULL
 		std::cout << "vm run" << std::endl;
// 	}
}
