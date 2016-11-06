#include <iostream>
#include <limits>
#include "Vm.class.hpp"
#include "IOperand.class.hpp"
#include "Operand.class.hpp"//_DEBUG_//

// template<typename U, typename V=float>
// class		Type
// {
// 	public:
// 	Type(void);
// 	Type(U val);
// 	Type(U val, V len);
// 
// 	~Type(void);
// 	
// 	U		val;
// 	V		len;
// };
// 
// template<typename U, typename V>
// Type<U, V>::Type(void)
// {
// 	val = 0;
// 	len = 0;
// }
// 
// template<typename U, typename V>
// Type<U, V>::~Type(void)
// {
// 	std::cout << "I am destroyed" << std::endl;
// }

class	Poly
{
	public:

	Poly(void);
	~Poly(void);

	virtual void	doStuff(void);
};

Poly::Poly()
{
	std::cout << "Poly construct" << std::endl;
}

Poly::~Poly()
{
	std::cout << "Poly destruct" << std::endl;
}

void	Poly::doStuff(void)
{
	std::cout << "Poly do stuff" << std::endl;
}


class	Child: public Poly
{
	public:
	Child(void);
	virtual ~Child(void);

	virtual void	doStuff(void);
};

Child::Child()
{
	std::cout << "Child construct" << std::endl; 
}

void	Child::doStuff(void)
{
	std::cout << "Child do stuff" << std::endl;
}

Child::~Child()
{
	std::cout << "Child destruct" << std::endl; 
}

void		test(void)
{
// 	Poly		*p = new Child();
// 	Child		*c = dynamic_cast<Child*>(p);
// 
// 	(void)p;
// 	(void)c;
// 	if (!c)
// 		std::cout << "c == NULL" << std::endl;
// 	else
// 		std::cout << "c == cast reussit" << std::endl;
	float	a = 3.01f;
	float	b = 0.5f;

	std::cout << a << " / " << b << " = " << a / b << std::endl;
// 	std::cout << a << " % " << b << " = " << a % b << std::endl;

// 	char		int_8;	//8 bit		1 octet
// 	short 		int_16;	//16 bit	2 octets
// 	int			int_32;	//32 bit	4 octets
// 
// 	(void)int_8;
// 	(void)int_16;
// 	(void)int_32;
// 	std::cout << std::numeric_limits<short>::min() << std::endl;//_DEBUG_//
// 	std::cout << "sizeof short : " << sizeof(short) * 8 << std::endl;//_DEBUG_//
// 	std::cout << std::numeric_limits<short int>::min() << std::endl;//_DEBUG_//
// 	std::cout << "sizeof short int : " << sizeof(short int) * 8 << std::endl;//_DEBUG_//
// 	std::cout << std::numeric_limits<int>::min() << std::endl;//_DEBUG_//
// 	std::cout << "sizeof int : " << sizeof(int) * 8 << std::endl;//_DEBUG_//
// 	std::cout << "------------------------------------------------------" << std::endl;//_DEBUG_//
// 	std::cout << "sizeof char = " << sizeof(char) << std::endl;//_DEBUG_//
// 	std::cout << "sizeof short = " << sizeof(short) << std::endl;//_DEBUG_//
// 	std::cout << "sizeof int = " << sizeof(int) << std::endl;//_DEBUG_//
// 	std::cout << "sizeof float = " << sizeof(float) << std::endl;//_DEBUG_//
		Operand<t_int8>		o(Int8, 10);
		Operand<t_int16>	e(Int16, 100);
		Operand<t_int32>	i(Int32, 100);
		Operand<t_double>	d(Double, 100.3);
		Operand<t_float>	f(Float, 100.98);
		IOperand const		*g;

		g = o + e; //int8
		(void)g;
		std::cout << (e * o)->toString() << std::endl; //int16
		e + i; //int16
		e + d; //Double
		e + f; //Float
		std::cout << "-----------------------" << std::endl;
		o / e; //int8
		e / o; //int16
		e / i; //int16
		e / d; //Double
		e / f; //Float
		std::cout << "-----------------------" << std::endl;
		o % e; //int8
		e % o; //int16
		e % i; //int16
		e % d; //Double
		e % f; //Float
		std::cout << "-----------------------" << std::endl;
		o - e; //int8
		e - o; //int16
		e - i; //int16
		e - d; //Double
		e - f; //Float
		std::cout << "-----------------------" << std::endl;
		o * e; //int8
		e * o; //int16
		e * i; //int16
		e * d; //Double
		e * f; //Float
 	std::cout << "sizeof double = " << sizeof(double) << std::endl;//_DEBUG_//
}
