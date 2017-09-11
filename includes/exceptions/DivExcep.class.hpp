#ifndef DIVEXCEP_CLASS_HPP
# define DIVEXCEP_CLASS_HPP

# include <iostream>

//maybe add iostream

class	DivExcep : public std::exception
{
	public :
//constructors
	DivExcep(void);
	DivExcep(DivExcep const &rhs);

//destructor
	virtual ~DivExcep(void) throw();

//operator overload
	DivExcep &operator=(DivExcep &rhs);	

//functions
// 	virtual const char *what(void) throw();
};

#endif
