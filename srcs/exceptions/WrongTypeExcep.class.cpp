#include "WrongTypeExcep.class.hpp"
//constructors
WrongTypeExcep::WrongTypeExcep(void)
{
}

WrongTypeExcep::WrongTypeExcep(WrongTypeExcep const &rhs)
{
	(void)rhs;
}

//destructor
WrongTypeExcep::~WrongTypeExcep(void)
{
}

//functions
const char *WrongTypeExcep::what(void) throw()
{
	return ("wrong type");
}
