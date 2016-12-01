#include  "ModExcep.class.hpp"

const char *ModExcep::what(void) throw()
{
	return ("wrong modulo operand");
}
