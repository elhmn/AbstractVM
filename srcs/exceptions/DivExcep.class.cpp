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
DivExcep::DivExcep(void) : std::runtime_error("")
{

}

DivExcep::DivExcep(DivExcep const &rhs) : std::runtime_error("")
{
	(void)rhs;
}

//destructor
DivExcep::~DivExcep(void) throw()
{

}

//functions
const char	*DivExcep::what(void) const throw()
{
	return ("division by zero");
}
