/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Excep.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 13:48:39 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/23 14:18:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEP_CLASS_HPP
# define EXCEP_CLASS_HPP

# include <iostream>

// runtime error exception
# define E_DIV					Excep<std::runtime_error>("Division by 0")
# define E_MOD					Excep<std::runtime_error>("Modulo by 0")
# define E_OVERFLOW				Excep<std::runtime_error>("Overflow")
# define E_DOWNFLOW				Excep<std::runtime_error>("Downflow")
# define E_EMPTYSTACK			Excep<std::runtime_error>("Empty stack")
# define E_NOEXIT				Excep<std::runtime_error>("No exit command")
# define E_ASSERT				Excep<std::runtime_error>("Assert not true")
# define E_FEWOPERAND			Excep<std::runtime_error>("Too few operand")

// logic error exception
# define E_LEXICAL(TEXT)		Excep<std::logic_error>( \
								std::string("Lexical error : ") + \
								TEXT)
# define E_SYNTAX(TEXT)			Excep<std::logic_error>( \
								std::string("Syntax error : ") + \
								TEXT)

//maybe add iostream
template<typename base_exception>
class	Excep : public base_exception
{
	private :

// attributes
	std::string		_what;

	public :

//constructors
	Excep(std::string what = "Except") :
			base_exception(what.c_str()), _what(what)
	{

	}

	Excep(Excep const &rhs) : base_exception(rhs.what())
	{
		*this = rhs;
	}

//destructor
	virtual ~Excep(void) throw()
	{

	}

//operator overload
	Excep const &operator=(Excep const &rhs)
	{
		(void)rhs;
		return (*this);
	}

//functions
	const char *what(void) const throw()
	{
		return (this->_what.c_str());
	}
};

#endif
