/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DivExcep.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:35:29 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/11 18:18:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DivExcep.class.hpp"

//constructors
DivExcep::DivExcep(void)
{
}

DivExcep::DivExcep(DivExcep const &rhs)
{
	(void)rhs;
}

//destructor
DivExcep::~DivExcep(void) throw()
{
}	

//functions
// const char	*DivExcep::what(void) throw()
// {
// 	return ("division by zero");
// }
