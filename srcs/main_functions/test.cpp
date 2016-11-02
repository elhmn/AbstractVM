#include <iostream>
#include <cstdint>

void		test(void)
{
	int8_t	i_8;
	int16_t	i_16;
	int32_t	i_32;

	i_8 = static_cast<int8_t>(8000); //Debug
	i_16 = static_cast<int16_t>(8000); //Debug
	i_32 = static_cast<int32_t>(8000); //Debug
	std::cout << "i_8 = [" << i_8 << "]" << std::endl; //Debug
	std::cout << "int8_max = [" << INT8_MAX << "]" << std::endl; //Debug
	std::cout << "int8_max = [" << INT8_MIN << "]" << std::endl; //Debug

	std::cout << "i_16 = [" << i_16 << "]" << std::endl; //Debug
	std::cout << "int16_max = [" << INT16_MAX << "]" << std::endl; //Debug
	std::cout << "int16_max = [" << INT16_MIN << "]" << std::endl; //Debug

	std::cout << "i_32 = [" << i_32 << "]" << std::endl; //Debug
	std::cout << "int32_max = [" << INT32_MAX << "]" << std::endl; //Debug
	std::cout << "int32_max = [" << INT32_MIN << "]" << std::endl; //Debug
}
