#include "Vm.class.hpp"
#include <iostream>

bool	Vm::verbose = false;
Vm		*Vm::_firstInstance = NULL;

//constructors
Vm::Vm(void)
{
	if (Vm::verbose)
		std::cout << "Vm constructor called" << std::endl;
}

//destructor
Vm::~Vm(void)
{
	if (Vm::verbose)
		std::cout << "vm destructor called" << std::endl;
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
