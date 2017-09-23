/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vm.class.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:35:35 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/23 14:41:01 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_CLASS_HPP
# define VM_CLASS_HPP

# include "Stack.class.hpp"

//c'est quoi encore la forme canonique ?
//- constructor par defaut
//- overload de l'operateur =
//- constructor par copy
//- destructeur eventuellement virtuel

class	Vm
{
	private :

//attributes
	static Vm			*_firstInstance;
	Stack				*_stack;
	bool				_running;

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
	Stack				*getStack(void) const;

//actions
 	static void			vm_exit(void);
	bool				stopped(void);
	void				start(void);
	void				stop(void);

//run
	void				run(std::string path);
};

#endif
