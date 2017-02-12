#include "Factory.class.hpp"
#include "Operand.class.hpp"
#include "vm_types.hpp"

Factory	*Factory::_firstInstance = NULL;
bool	Factory::_verbose = false;

//constructor
Factory::Factory(void)
{
	if (Factory::_verbose)
	{
		std::cout << "Constructor called" << std::endl;
	}
}

//destructor
Factory::~Factory(void)
{
	if (Factory::_verbose)
	{
		std::cout << "Destructor called" << std::endl;
	}
}

//getters
Factory *Factory::getInstance(void)
{
	if (!Factory::_firstInstance)
		Factory::_firstInstance = new Factory();
	return (Factory::_firstInstance);
}

//factory method
IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
	try
	{
//catch down and upcast exceptions
		switch (type)
		{
			case Int8:
				return (new Operand<t_int8>(Int8,
						static_cast<t_int8>(std::stoi(value))));
				break;
			case Int16:
				return (new Operand<t_int16>(Int16,
						static_cast<t_int16>(std::stod(value))));
				break;
			case Int32:
				return (new Operand<t_int32>(Int32,
						static_cast<t_int32>(std::stod(value))));
				break;
			case Float:
				return (new Operand<t_float>(Float,
						static_cast<t_float>(std::stod(value))));
				break;
			case Double:
				return (new Operand<t_double>(Double,
						static_cast<t_double>(std::stod(value))));
				break;
			default:
				std::cout << "unknown type" << std::endl; //must be an exception
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception :: " << e.what() << std::endl;
	}
	return (NULL);
}
