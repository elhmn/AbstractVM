/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:19:04 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/11 17:40:27 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class		Excep : public std::exception
{
	public :

	virtual const char* what() throw()
	{
		return ("bonjour copain");
	}

};

void		test(void) throw(Excep)
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
