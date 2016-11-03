#include <iostream>
#include <limits>
#include "Vm.class.hpp"
#include "IOperand.class.hpp"

void		test(void)
{
	char		int_8;	//8 bit		1 octet
	short 		int_16;	//16 bit	2 octets
	int			int_32;	//32 bit	4 octets

	(void)int_8;
	(void)int_16;
	(void)int_32;
	std::cout << std::numeric_limits<short>::min() << std::endl;//_DEBUG_//
	std::cout << "sizeof short : " << sizeof(short) * 8 << std::endl;//_DEBUG_//
	std::cout << std::numeric_limits<short int>::min() << std::endl;//_DEBUG_//
	std::cout << "sizeof short int : " << sizeof(short int) * 8 << std::endl;//_DEBUG_//
	std::cout << std::numeric_limits<int>::min() << std::endl;//_DEBUG_//
	std::cout << "sizeof int : " << sizeof(int) * 8 << std::endl;//_DEBUG_//
}
