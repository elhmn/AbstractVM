/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:35:17 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/19 23:45:38 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	this->_f_tab.push_back(&Factory::createInt8);
	this->_f_tab.push_back(&Factory::createInt16);
	this->_f_tab.push_back(&Factory::createInt32);
	this->_f_tab.push_back(&Factory::createFloat);
	this->_f_tab.push_back(&Factory::createDouble);
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

//factory operand creator method
IOperand const	*Factory::createInt8(std::string const &value) const
{
	std::cout << "Create Int8 : " << value << std::endl;
	return (new Operand<t_int8>(Int8,
		static_cast<t_int8>(std::stod(value))));
}

IOperand const	*Factory::createInt16(std::string const &value) const
{
	std::cout << "Create Int16 : " << value << std::endl;
	return (new Operand<t_int16>(Int16,
			static_cast<t_int16>(std::stod(value))));
}

IOperand const	*Factory::createInt32(std::string const &value) const
{
	std::cout << "Create Int32 : " << value << std::endl;
	return (new Operand<t_int32>(Int32,
			static_cast<t_int32>(std::stod(value))));
}

IOperand const	*Factory::createFloat(std::string const &value) const
{
	std::cout << "Create Float : " << value << std::endl;
	return (new Operand<t_float>(Float,
			static_cast<t_float>(std::stod(value))));
}

IOperand const	*Factory::createDouble(std::string const &value) const
{
	std::cout << "Create Double : " << value << std::endl;
	return (new Operand<t_double>(Double,
			static_cast<t_double>(std::stod(value))));
}

//factory method
IOperand const *Factory::createOperand(eOperandType type,
					std::string const &value) const
{
	int		i;

	i = -1;
//catch down and upcast exceptions
	try
	{
		while (++i < static_cast<int>(this->_f_tab.size()))
		{
			if (i == type)
				return ((this->*_f_tab[i])(value));
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception :: " << e.what() << std::endl;
	}
	std::cout << "unknown type" << std::endl; //must be an exception
	return (NULL);
}
