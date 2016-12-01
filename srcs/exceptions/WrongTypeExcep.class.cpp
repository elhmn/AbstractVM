#include "WrongTypeExcep.class.hpp"

const char *WrongTypeExcep::what(void) throw()
{
	return ("wrong type");
}
