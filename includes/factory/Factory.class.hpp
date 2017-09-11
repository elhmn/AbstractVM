#ifndef FACTORY_CLASS_HPP
# define FACTORY_CLASS_HPP

#include "IOperand.class.hpp"
#include <string>
#include <vector>


class	Factory
{

//typedef
	typedef IOperand const	*(Factory::*t_f)(std::string const &) const;

//attributs
	private:
	static Factory		*_firstInstance;
	std::vector<t_f>	_f_tab;

	public:
	static bool			_verbose;

	private:

//constructors
	Factory(void);
	Factory(Factory const &rhs);

//operator overload
	Factory &operator=(Factory const &rhs);

//destructor
	~Factory(void);

//factory operand creator method
	IOperand const		*createInt8(std::string const &value) const;
	IOperand const		*createInt16(std::string const &value) const;
	IOperand const		*createInt32(std::string const &value) const;
	IOperand const		*createFloat(std::string const &value) const;
	IOperand const		*createDouble(std::string const &value) const;

	public:
//getters
	static Factory		 *getInstance(void);

//factory method
	IOperand const		*createOperand(eOperandType type,
						std::string const& value) const;
};

#endif
