#ifndef INT8_CLASS_HPP
# define INT8_CLASS_HPP

# include "IOperand.class.hpp"

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
	~Operand(void);

//operator overload
	IOperand const &operator=(IOperand const &rhs) const;

//IOperand interface
	int getPrecision( void ) const; // Precision of the type of the instance
	eOperandType getType(void) const; // Type of the instance
	IOperand const * operator+(IOperand const & rhs) const; // Sum
	IOperand const * operator-(IOperand const & rhs) const; // Difference
	IOperand const * operator*(IOperand const & rhs) const; // Product
	IOperand const * operator/(IOperand const & rhs) const; // Quotient
	IOperand const * operator%(IOperand const & rhs) const; // Modulo
	std::string const & toString(void) const; // String representation of the instance

	private:
//value
	T				_val;
	eOperandType	_type;
};

template<typename T>
bool	Operand<T>::verbose = false;

template<typename T>
Operand<T>::Operand(eOperandType type, T val) : _val(val), _type(type)
{
	if (Operand<T>::verbose)
		std::cout << "Operand constructor called" << std::endl;
	// check that the value is not out of range
	// if the value is out range crop it to max value 
	// er let c+ compiler do is own stuff
}

template<typename T>
Operand<T>::~Operand(void)
{
	if (Operand<T>::verbose)
		std::cout << "Operand destructor called" << std::endl;
}

template<typename T>
int		Operand<T>::getPrecision(void) const
{
	return (this->_type);
}

#endif
