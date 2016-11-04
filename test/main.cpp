#include <iostream>
#include <stack>

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

	std::stack<int>	s;
	int				i;

 	for (i = 0; i < 10; i++)
 	{
		s.push(i);
		std::cout << "i = [" << i << "]" << std::endl;
	}
	while (!s.empty())
	{
		std::cout << "s = " << s.top() << std::endl;
		s.pop();
	}
	return (0);
}
