/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongTypeExcep.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:35:22 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/11 18:18:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongTypeExcep.class.hpp"

//constructors
WrongTypeExcep::WrongTypeExcep(void)
{
}

WrongTypeExcep::WrongTypeExcep(WrongTypeExcep const &rhs)
{
	(void)rhs;
}

//destructor
WrongTypeExcep::~WrongTypeExcep(void) throw()
{
}

//functions
// const char	*WrongTypeExcep::what(void) throw()
// {
// 	return ("wrong type");
// }
