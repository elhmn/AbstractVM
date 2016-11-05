#include "Operand.class.hpp"

bool		Operand::verbose = false;

Operand::Operand(void)
{
	if (Operand::verbose)
		std::cout << "Operand constructor called" << std::endl;
}

Operand::~Operand(void)
{
	if (Operand::verbose)
		std::cout << "Operand destructor called" << std::endl;
}
