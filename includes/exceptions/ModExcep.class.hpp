#ifndef MODEXCEP_CLASS_HPP
# define MODEXCEP_CLASS_HPP

# include <iostream>

class	ModExcep : public std::exception
{
	public:
	
	virtual const char *what(void) throw();
};

#endif
