#ifndef WRONGTYPEEXCEP_CLASS_HPP
# define WRONGTYPEEXCEP_CLASS_HPP

# include <iostream>

class	WrongTypeExcep : public std::exception
{
	public :
//constructors
	WrongTypeExcep(void);
	WrongTypeExcep(WrongTypeExcep const &rhs);

//destructor
	virtual ~WrongTypeExcep(void) throw();

//operator overload
	WrongTypeExcep &operator=(WrongTypeExcep &rhs);

//functions
// 	virtual const char *what(void) throw();
};

#endif
