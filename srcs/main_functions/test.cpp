#include <iostream>
#include <limits>

void		test(void)
{
	char		s_8; //8 bit 1 octet
	short 		s_16; //16 bit 2 octets
	int			s_32; //32 bit	4 octets

	(void)s_8;
	(void)s_16;
	(void)s_32;
	std::cout << std::numeric_limits<short>::min() << std::endl;
	std::cout << "sizeof short : " << sizeof(short) * 8 << std::endl;
	std::cout << std::numeric_limits<short int>::min() << std::endl;
	std::cout << "sizeof short int : " << sizeof(short int) * 8 << std::endl;
	std::cout << std::numeric_limits<int>::min() << std::endl;
	std::cout << "sizeof int : " << sizeof(int) * 8 << std::endl;
}
