#include <iostream>

class		Excep : public std::exception
{
	public :
	virtual const char* what() throw()
	{
		return ("bonjour copain");
	}
};

void		test(void)
{
	throw Excep();
}

int		main(void)
{
	try
	{
		test();
	}
	catch (Excep &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Exception catched" << std::endl;
	}
	return (0);
}
