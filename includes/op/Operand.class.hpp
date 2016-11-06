#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

# include "IOperand.class.hpp"
# include <typeinfo>
# include <vector>
# include <sstream>

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

//IOperand interface

// getters
	virtual int getPrecision( void ) const; // Precision of the type of the instance
	virtual eOperandType getType(void) const; // Type of the instance

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
Operand<t_int8> const	*castInt8(void *op);
Operand<t_int16> const	*castInt16(void *op);
Operand<t_int32> const	*castInt32(void *op);
Operand<t_float> const	*castFloat(void *op);
Operand<t_double> const	*castDouble(void *op);

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
	// er let c+ compiler do is own stuff
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
int		Operand<T>::getPrecision(void) const
{
	return (this->_type);
}

template<typename T>
eOperandType	Operand<T>::getType(void) const
{
	return (this->_type);
}

//operator overload
template<typename T>
IOperand const *Operand<T>::operator+(IOperand const &rhs) const
{
	eOperandType		type;

	type = (this->getPrecision() < rhs.getPrecision()) ? rhs.getType() : this->getType();
	(void)type;
	if (rhs.getType() == Int8)
	{
 		Operand<t_int8> const	*op = dynamic_cast<Operand<t_int8> const *>(&rhs);
		if (op)
		{
			std::cout << "int8 good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() + op->getValue())));
		}
	}
	else if (rhs.getType() == Int16)
	{
 		Operand<t_int16> const	*op = dynamic_cast<Operand<t_int16> const *>(&rhs);
		if (op)
		{
			std::cout << "int16 good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() + op->getValue())));
		}
	}
	else if (rhs.getType() == Int32)
	{
 		Operand<t_int32> const	*op = dynamic_cast<Operand<t_int32> const *>(&rhs);
		if (op)
		{
			std::cout << "int32 good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() + op->getValue())));
		}
	}
	else if (rhs.getType() == Float)
	{
 		Operand<t_float> const	*op = dynamic_cast<Operand<t_float> const *>(&rhs);
		if (op)
		{
			std::cout << "Float good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() + op->getValue())));
		}
	}
	else if (rhs.getType() == Double)
	{
 		Operand<t_double> const	*op = dynamic_cast<Operand<t_double> const *>(&rhs);
		if (op)
		{
			std::cout << "Double good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() + op->getValue())));
		}
	}
	std::cout << "Error " << std::endl;
	return (NULL);
}

template<typename T>
IOperand const *Operand<T>::operator-(IOperand const &rhs) const
{
	eOperandType	type;

	type = (this->getPrecision() < rhs.getPrecision()) ? rhs.getType() : this->getType();
	if (rhs.getType() == Int8)
	{
 		Operand<t_int8> const	*op = dynamic_cast<Operand<t_int8> const *>(&rhs);
		if (op)
		{
			std::cout << "int8 good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() - op->getValue())));
		}
	}
	else if (rhs.getType() == Int16)
	{
 		Operand<t_int16> const	*op = dynamic_cast<Operand<t_int16> const *>(&rhs);
		if (op)
		{
			std::cout << "int16 good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() - op->getValue())));
		}
	}
	else if (rhs.getType() == Int32)
	{
 		Operand<t_int32> const	*op = dynamic_cast<Operand<t_int32> const *>(&rhs);
		if (op)
		{
			std::cout << "int32 good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() - op->getValue())));
		}
	}
	else if (rhs.getType() == Float)
	{
 		Operand<t_float> const	*op = dynamic_cast<Operand<t_float> const *>(&rhs);
		if (op)
		{
			std::cout << "Float good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() - op->getValue())));
		}
	}
	else if (rhs.getType() == Double)
	{
 		Operand<t_double> const	*op = dynamic_cast<Operand<t_double> const *>(&rhs);
		if (op)
		{
			std::cout << "Double good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() - op->getValue())));
		}
	}
	std::cout << "Error " << std::endl;//_DEBUG_//
	return (NULL);
	// here you must use Operand factory (not sure)
}

template<typename T>
IOperand const *Operand<T>::operator*(IOperand const &rhs) const
{
	eOperandType	type;

	type = (this->getPrecision() < rhs.getPrecision()) ? rhs.getType() : this->getType();
	if (rhs.getType() == Int8)
	{
 		Operand<t_int8> const	*op = dynamic_cast<Operand<t_int8> const *>(&rhs);
		if (op)
		{
			std::cout << "int8 good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() * op->getValue())));
		}
	}
	else if (rhs.getType() == Int16)
	{
 		Operand<t_int16> const	*op = dynamic_cast<Operand<t_int16> const *>(&rhs);
		if (op)
		{
			std::cout << "int16 good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() * op->getValue())));
		}
	}
	else if (rhs.getType() == Int32)
	{
 		Operand<t_int32> const	*op = dynamic_cast<Operand<t_int32> const *>(&rhs);
		if (op)
		{
			std::cout << "int32 good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() * op->getValue())));
		}
	}
	else if (rhs.getType() == Float)
	{
 		Operand<t_float> const	*op = dynamic_cast<Operand<t_float> const *>(&rhs);
		if (op)
		{
			std::cout << "Float good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() * op->getValue())));
		}
	}
	else if (rhs.getType() == Double)
	{
 		Operand<t_double> const	*op = dynamic_cast<Operand<t_double> const *>(&rhs);
		if (op)
		{
			std::cout << "Double good cast " << std::endl;//_DEBUG_//
			return (static_cast<IOperand const *>(new Operand(type, this->getValue() * op->getValue())));
		}
	}
	std::cout << "Error " << std::endl;//_DEBUG_//
	return (NULL);
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
			std::cout << "int8 good cast " << std::endl;//_DEBUG_//
		 	return (static_cast<IOperand const *>(new Operand(type, this->getValue() / op->getValue())));
		}
	}
	else if (rhs.getType() == Int16)
	{
 		Operand<t_int16> const	*op = dynamic_cast<Operand<t_int16> const *>(&rhs);
		if (op)
		{
			std::cout << "int16 good cast " << std::endl;//_DEBUG_//
		 	return (static_cast<IOperand const *>(new Operand(type, this->getValue() / op->getValue())));
		}
	}
	else if (rhs.getType() == Int32)
	{
 		Operand<t_int32> const	*op = dynamic_cast<Operand<t_int32> const *>(&rhs);
		if (op)
		{
			std::cout << "int32 good cast " << std::endl;//_DEBUG_//
		 	return (static_cast<IOperand const *>(new Operand(type, this->getValue() / op->getValue())));
		}
	}
	else if (rhs.getType() == Float)
	{
 		Operand<t_float> const	*op = dynamic_cast<Operand<t_float> const *>(&rhs);
		if (op)
		{
			std::cout << "Float good cast " << std::endl;//_DEBUG_//
 			return (static_cast<IOperand const *>(new Operand(type, this->getValue() / op->getValue())));
		}
	}
	else if (rhs.getType() == Double)
	{
 		Operand<t_double> const	*op = dynamic_cast<Operand<t_double> const *>(&rhs);
		if (op)
		{
			std::cout << "Double good cast " << std::endl;//_DEBUG_//
		 	return (static_cast<IOperand const *>(new Operand(type, this->getValue() / op->getValue())));
		}
	}
	// here you must use Operand factory (not sure)
	// if denum == 0 throw exeption
	std::cout << "Error " << std::endl;//_DEBUG_//
	return (NULL);

}

template<typename T>
IOperand const *Operand<T>::operator%(IOperand const &rhs) const
{
	eOperandType	type;

	if (this->getType() == Double || this->getType() == Float
		|| rhs.getType() == Float || rhs.getType() == Double)
		return (NULL); //do something in that case
	type = (this->getPrecision() < rhs.getPrecision()) ? rhs.getType() : this->getType();
	if (rhs.getType() == Int8)
	{
 		Operand<t_int8> const	*op = dynamic_cast<Operand<t_int8> const *>(&rhs);
		if (op)
		{
			std::cout << "int8 good cast " << std::endl;//_DEBUG_//
		 	return (static_cast<IOperand const *>(new Operand(type, static_cast<t_int32>(this->getValue()) % static_cast<t_int32>(op->getValue()))));
		}
	}
	else if (rhs.getType() == Int16)
	{
 		Operand<t_int16> const	*op = dynamic_cast<Operand<t_int16> const *>(&rhs);
		if (op)
		{
			std::cout << "int16 good cast " << std::endl;//_DEBUG_//
		 	return (static_cast<IOperand const *>(new Operand(type, static_cast<t_int32>(this->getValue()) % static_cast<t_int32>(op->getValue()))));
		}
	}
	else if (rhs.getType() == Int32)
	{
 		Operand<t_int32> const	*op = dynamic_cast<Operand<t_int32> const *>(&rhs);
		if (op)
		{
			std::cout << "int32 good cast " << std::endl;//_DEBUG_//
		 	return (static_cast<IOperand const *>(new Operand(type, static_cast<t_int32>(this->getValue()) % static_cast<t_int32>(op->getValue()))));
		}
	}
	else if (rhs.getType() == Float)
	{
 		Operand<t_float> const	*op = dynamic_cast<Operand<t_float> const *>(&rhs);
		if (op)
		{
			std::cout << "Float good cast " << std::endl;//_DEBUG_//
 			return (static_cast<IOperand const *>(new Operand(type, static_cast<t_int32>(this->getValue()) % static_cast<t_int32>(op->getValue()))));
		}
	}
	else if (rhs.getType() == Double)
	{
 		Operand<t_double> const	*op = dynamic_cast<Operand<t_double> const *>(&rhs);
		if (op)
		{
			std::cout << "Double good cast " << std::endl;//_DEBUG_//
		 	return (static_cast<IOperand const *>(new Operand(type, static_cast<t_int32>(this->getValue()) % static_cast<t_int32>(op->getValue()))));
		}
	}
	// here you must use Operand factory (not sure)
	// if denum == 0 throw exeption
	std::cout << "Error " << std::endl;//_DEBUG_//
	return (NULL);
}

template<typename T>
std::string const & Operand<T>::toString(void) const
{
	return (this->_sVal);
}

#endif
