#ifndef WRONGTYPEEXCEP_CLASS_HPP
# define WRONGTYPEEXCEP_CLASS_HPP

# include <iostream>

class	WrongTypeExcep : public std::logic_error
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
	const char *what(void) const throw();
};

#endif
