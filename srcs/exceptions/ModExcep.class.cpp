#include  "ModExcep.class.hpp"

//constructors
ModExcep::ModExcep(void)
{
}

ModExcep::ModExcep(ModExcep const &rhs)
{
	(void)rhs;
}

//destructor
ModExcep::~ModExcep(void)
{
}

//functions
const char *ModExcep::what(void) throw()
{
	return ("wrong modulo operand");
}
