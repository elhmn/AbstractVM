#ifndef VM_CLASS_HPP
# define VM_CLASS_HPP

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

//constructors
	Vm(void);
	Vm(Vm const &Vm);

//destructors
	~Vm(void);

//operator overload
	Vm		&operator=(Vm const &rhs);

	public :
//attributs
	static bool			verbose;

//getters
	static Vm	*getInstance(void);
};

#endif
