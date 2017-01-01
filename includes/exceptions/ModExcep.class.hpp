#ifndef MODEXCEP_CLASS_HPP
# define MODEXCEP_CLASS_HPP

# include <iostream>

class	ModExcep : public std::exception
{
	public :
//constructors
	ModExcep(void);
	ModExcep(ModExcep const &rhs);

//destructor
	~ModExcep(void);

//operator overload
	ModExcep &operator=(ModExcep &rhs);	

//functions
	virtual const char *what(void) throw();
};

#endif
