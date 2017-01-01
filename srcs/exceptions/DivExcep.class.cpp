#include "DivExcep.class.hpp"

//constructors
DivExcep::DivExcep(void)
{
}

DivExcep::DivExcep(DivExcep const &rhs)
{
	(void)rhs;
}

//destructor
DivExcep::~DivExcep(void)
{
}

//functions
const char *DivExcep::what(void) throw()
{
	return ("division by zero");
}
