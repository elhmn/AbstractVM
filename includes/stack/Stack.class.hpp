#ifndef STACK_CLASS_HPP
# define STACK_CLASS_HPP

# include <stack>
# include "IOperand.class.hpp"

class	Stack
{
	private:
//attributs
	std::stack<IOperand const*>		*_stack;

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
	std::stack<IOperand const*>	*getStack(void) const;

//actions
	void	assert(IOperand const *o) const;
	void	push(IOperand const *o);
	void	print(void) const;
	void	dump(void) const;
	void	pop(void);
	void	add(void);
	void	sub(void);
	void	mul(void);
	void	div(void);
	void	mod(void);
};

#endif
