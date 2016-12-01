#ifndef DIVEXCEP_CLASS_HPP
# define DIVEXCEP_CLASS_HPP

# include <iostream>

//maybe add iostream

class	DivExcep : public std::exception
{
	public :
	virtual const char *what(void) throw();
};

#endif
