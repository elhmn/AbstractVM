#ifndef FACTORY_CLASS_HPP
# define FACTORY_CLASS_HPP

#include "IOperand.class.hpp"
#include <string>

class	Factory
{

//attributs
	private:
	static Factory	*_firstInstance;

	public:
	static bool		_verbose;

	private:
//constructors
	Factory(void);
	Factory(Factory const &rhs);

//operator overload
	Factory &operator=(Factory const &rhs);

//destructor
	~Factory(void);

	public:
//getters
	static Factory *getInstance(void);

//factory method
	IOperand const* createOperand(eOperandType type, std::string const& value)const;
};

#endif
