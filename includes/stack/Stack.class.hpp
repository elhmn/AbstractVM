#ifndef STACK_CLASS_HPP
# define STACK_CLASS_HPP

# include <stack>
# include "IOperand.class.hpp"

class	Stack
{
	private:
//attributs
	std::stack<IOperand*>		*_stack;

	public:
//attributs
	static bool					verbose;

//constructors
	Stack(void);
	Stack(Stack const &src);

//destructor
	~Stack(void);

//operator overload
	Stack	&operator=(Stack const &rhs);

//getters
	Stack	&getStack(void) const;

//actions
//--------------------//

};

#endif
