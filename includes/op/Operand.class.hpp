/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 17:20:02 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/23 15:53:17 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

# include <typeinfo>
# include <vector>
# include <sstream>
# include <cmath>
#include "error.h"
# include "IOperand.class.hpp"
# include "Excep.class.hpp"
# include "Factory.class.hpp"

// TODO:
// - Exception handling (i'll do that later)

template<typename T>
class		 Operand: public IOperand
{
	public:
//attributs
	static bool		verbose;

//contructors
	Operand(void);
	Operand(eOperandType type, T val);
	Operand(Operand const &src);

//destructor
	virtual ~Operand(void);

//operator overload
	IOperand &operator=(IOperand const &rhs);

//getters
	T	getValue(void) const;
	std::string		getSVal(void) const;

//IOperand interface

// getters
	virtual int getPrecision(void) const; // Precision of the type of the instance
	virtual eOperandType getType(void) const; // Type of the instance

// actions
	static std::string		nbrToString(eOperandType type, t_double val);

// operator overload
	virtual IOperand const * operator+(IOperand const & rhs) const; // Sum
	virtual IOperand const * operator-(IOperand const & rhs) const; // Difference
	virtual IOperand const * operator*(IOperand const & rhs) const; // Product
	virtual IOperand const * operator/(IOperand const & rhs) const; // Quotient
	virtual IOperand const * operator%(IOperand const & rhs) const; // Modulo
	virtual std::string const & toString(void) const; // String representation of the instance

	private:
//value
	T				_val;
	std::string		_sVal;
	eOperandType	_type;
};


//operand cast
Operand<t_int8> const	*castInt8(const IOperand *op);
Operand<t_int16> const	*castInt16(const IOperand *op);
Operand<t_int32> const	*castInt32(const IOperand *op);
Operand<t_float> const	*castFloat(const IOperand *op);
Operand<t_double> const	*castDouble(const IOperand *op);

template<typename T>
bool	Operand<T>::verbose = false;

//constructors
template<typename T>
Operand<T>::Operand(eOperandType type, T val) : _val(val), _type(type)
{
	std::stringstream	ss;

	if (Operand<T>::verbose)
		std::cout << "Operand constructor called" << std::endl;
	// check that the value is not out of range
	// if the value is out range crop it to max value
	// or let c++ compiler do is own stuff
	//
	// Also if it is a int8 (a char then) cast it into a int16
//// 	std::cout << "this->_val = " << this->_val << std::endl;//_DEBUG_//
	if (type == Int8)
		ss << static_cast<t_int16>(this->_val);
	else
		ss << this->_val;
	this->_sVal = ss.str();
}

//destructor
template<typename T>
Operand<T>::~Operand(void)
{
	if (Operand<T>::verbose)
		std::cout << "Operand destructor called" << std::endl;
}

//getters
template<typename T>
T	Operand<T>::getValue(void) const
{
	return (this->_val);
}

template<typename T>
std::string		Operand<T>::getSVal(void) const
{
	return (this->_sVal);
}

template<typename T>
int		Operand<T>::getPrecision(void) const
{
	return (this->_type);
}

template<typename T>
eOperandType	Operand<T>::getType(void) const
{
	return (this->_type);
}

//actions
template<typename T>
std::string		Operand<T>::nbrToString(eOperandType type, t_double val)
{
	std::stringstream	ss;

//	std::cout << "val = " << val << std::endl;//_DEBUG_//
	if (type == Int8
		|| type == Int16)
		ss << static_cast<t_int16>(val);
	else if (type == Int32)
		ss << static_cast<t_int32>(val);
	else if (type == Float)
		ss << static_cast<t_float>(val);
	else
		ss << static_cast<t_double>(val);
	return (ss.str());
}

//operator overload
template<typename T>
IOperand const *Operand<T>::operator+(IOperand const &rhs) const
{
	eOperandType		type;

	type = (this->getPrecision() < rhs.getPrecision()) ? rhs.getType() : this->getType();
	return (Factory::getInstance()->createOperand(type, nbrToString(type,
			this->getValue() + std::stod(rhs.toString()))));
}

template<typename T>
IOperand const *Operand<T>::operator-(IOperand const &rhs) const
{
	eOperandType	type;

	type = (this->getPrecision() < rhs.getPrecision()) ? rhs.getType() : this->getType();
	return (Factory::getInstance()->createOperand(type, nbrToString(type,
			this->getValue() - std::stod(rhs.toString()))));
}

template<typename T>
IOperand const *Operand<T>::operator*(IOperand const &rhs) const
{
	eOperandType	type;

	type = (this->getPrecision() < rhs.getPrecision()) ? rhs.getType() : this->getType();
	return (Factory::getInstance()->createOperand(type, nbrToString(type,
			this->getValue() * std::stod(rhs.toString()))));
}

template<typename T>
IOperand const *Operand<T>::operator/(IOperand const &rhs) const
{
	eOperandType	type;

	type = (this->getPrecision() < rhs.getPrecision()) ? rhs.getType() : this->getType();
	if (rhs.getType() == Int8)
	{
 		Operand<t_int8> const	*op = dynamic_cast<Operand<t_int8> const *>(&rhs);
		if (op)
		{
			if (op->getValue() == 0)
				throw E_DIV;
//			std::cout << "int8 good cast " << std::endl;//_DEBUG_//
		 	return (Factory::getInstance()->createOperand(type, nbrToString(type,
					this->getValue() / op->getValue())));
		}
	}
	else if (rhs.getType() == Int16)
	{
 		Operand<t_int16> const	*op = dynamic_cast<Operand<t_int16> const *>(&rhs);
		if (op)
		{
			if (op->getValue() == 0)
				throw E_DIV;
//			std::cout << "int16 good cast " << std::endl;//_DEBUG_//
		 	return (Factory::getInstance()->createOperand(type, nbrToString(type,
					this->getValue() / op->getValue())));
		}
	}
	else if (rhs.getType() == Int32)
	{
 		Operand<t_int32> const	*op = dynamic_cast<Operand<t_int32> const *>(&rhs);
		if (op)
		{
			if (op->getValue() == 0)
				throw E_DIV;
//			std::cout << "int32 good cast " << std::endl;//_DEBUG_//
		 	return (Factory::getInstance()->createOperand(type, nbrToString(type,
					this->getValue() / op->getValue())));
		}
	}
	else if (rhs.getType() == Float)
	{
 		Operand<t_float> const	*op = dynamic_cast<Operand<t_float> const *>(&rhs);
		if (op)
		{
			if (op->getValue() == 0)
				throw E_DIV;
//			std::cout << "Float good cast " << std::endl;//_DEBUG_//
 			return (Factory::getInstance()->createOperand(type, nbrToString(type,
					this->getValue() / op->getValue())));
		}
	}
	else if (rhs.getType() == Double)
	{
 		Operand<t_double> const	*op = dynamic_cast<Operand<t_double> const *>(&rhs);
		if (op)
		{
			if (op->getValue() == 0)
				throw E_DIV;
//			std::cout << "Double good cast " << std::endl;//_DEBUG_//
		 	return (Factory::getInstance()->createOperand(type, nbrToString(type,
					this->getValue() / op->getValue())));
		}
	}
	return (NULL);

}

template<typename T>
IOperand const *Operand<T>::operator%(IOperand const &rhs) const
{
	eOperandType	type;

	type = (this->getPrecision() < rhs.getPrecision()) ? rhs.getType() : this->getType();
	if (rhs.getType() == Int8)
	{
 		Operand<t_int8> const	*op = dynamic_cast<Operand<t_int8> const *>(&rhs);
		if (op)
		{
			if (op->getValue() == 0)
				throw E_MOD;
//			std::cout << "int8 good cast " << std::endl;//_DEBUG_//
		 	return (Factory::getInstance()->createOperand(type, nbrToString(type,
					fmod(static_cast<t_double>(this->getValue()), static_cast<t_double>(op->getValue())))));
		}
	}
	else if (rhs.getType() == Int16)
	{
 		Operand<t_int16> const	*op = dynamic_cast<Operand<t_int16> const *>(&rhs);
		if (op)
		{
			if (op->getValue() == 0)
				throw E_MOD;
//			std::cout << "int16 good cast " << std::endl;//_DEBUG_//
		 	return (Factory::getInstance()->createOperand(type, nbrToString(type,
					fmod(static_cast<t_double>(this->getValue()), static_cast<t_double>(op->getValue())))));
		}
	}
	else if (rhs.getType() == Int32)
	{
 		Operand<t_int32> const	*op = dynamic_cast<Operand<t_int32> const *>(&rhs);
		if (op)
		{
			if (op->getValue() == 0)
				throw E_MOD;
//			std::cout << "int32 good cast " << std::endl;//_DEBUG_//
		 	return (Factory::getInstance()->createOperand(type, nbrToString(type,
					fmod(static_cast<t_double>(this->getValue()), static_cast<t_double>(op->getValue())))));
		}
	}
	else if (rhs.getType() == Float)
	{
 		Operand<t_float> const	*op = dynamic_cast<Operand<t_float> const *>(&rhs);
		if (op)
		{
			if (op->getValue() == 0)
				throw E_MOD;
//			std::cout << "Float good cast " << std::endl;//_DEBUG_//
		 	return (Factory::getInstance()->createOperand(type, nbrToString(type,
					fmod(static_cast<t_double>(this->getValue()), static_cast<t_double>(op->getValue())))));
		}
	}
	else if (rhs.getType() == Double)
	{
 		Operand<t_double> const	*op = dynamic_cast<Operand<t_double> const *>(&rhs);
		if (op)
		{
			if (op->getValue() == 0)
				throw E_MOD;
//			std::cout << "Double good cast " << std::endl;//_DEBUG_//
		 	return (Factory::getInstance()->createOperand(type, nbrToString(type,
					fmod(static_cast<t_double>(this->getValue()), static_cast<t_double>(op->getValue())))));
		}
	}
	return (NULL);
}

template<typename T>
std::string const & Operand<T>::toString(void) const
{
	return (this->_sVal);
}

#endif
