#ifndef WRONGTYPEEXCEP_CLASS_HPP
# define WRONGTYPEEXCEP_CLASS_HPP

# include <iostream>

class	WrongTypeExcep : public std::exception
{
	public :
	virtual const char *what(void) throw();
};

#endif
