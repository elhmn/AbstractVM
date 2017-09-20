#ifndef EXCEP_CLASS_HPP
# define EXCEP_CLASS_HPP

# include <iostream>

//maybe add iostream
template<typename base_exception>
class	Excep : public base_exception
{
	private :

// attributes
	std::string		_what;

	public :
//constructors
// 	Excep(void) : _what("Excep"), base_exception(_what().c_str())
// 	{
// 
// 	}

	Excep(std::string what = "Except") : base_exception(what.c_str()), _what(what) 
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
