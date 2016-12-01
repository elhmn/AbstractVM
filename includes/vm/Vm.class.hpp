#ifndef VM_CLASS_HPP
# define VM_CLASS_HPP

# include "Stack.class.hpp"

//c'est quoi encore la forme canonique
//- constructor par defaut
//- overload de l'operateur =
//- constructor par copy
//- destructeur eventuellement virtuel

class	Vm
{
	private :

//attributs
	static Vm			*_firstInstance;
	Stack				*_stack;

//constructors
	Vm(void);
	Vm(Vm const &Vm);

//destructor
	~Vm(void);

//operator overload
	Vm		&operator=(Vm const &rhs);

	public :
//attributs
	static bool			verbose;

//getters
	static Vm			*getInstance(void);

//actions
 	static void				vm_exit(void);

//run
	void				run(void);
	void				run(std::string path);
};

#endif
