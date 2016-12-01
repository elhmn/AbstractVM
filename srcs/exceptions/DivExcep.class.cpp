#include "DivExcep.class.hpp"

const char *DivExcep::what(void) throw()
{
	return ("division by zero");
}
