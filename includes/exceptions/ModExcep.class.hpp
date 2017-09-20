#ifndef MODEXCEP_CLASS_HPP
# define MODEXCEP_CLASS_HPP

# include <iostream>

class	ModExcep : public std::runtime_error
{
	public :
//constructors
	ModExcep(void);
	ModExcep(ModExcep const &rhs);

//destructor
	virtual ~ModExcep(void) throw();

//operator overload
	ModExcep &operator=(ModExcep &rhs);	

//functions
	const char *what(void) const throw();
};

#endif
