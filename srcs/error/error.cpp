#include <stdlib.h>
#include <iostream>

void					error(const char *msg,
								const char *file, int line)
{
	std::cerr << "Error : " << file << " : " << line;
	if (msg)
		std::cerr << " : " << msg;
	std::cerr << std::endl;
	exit(-1);
}
