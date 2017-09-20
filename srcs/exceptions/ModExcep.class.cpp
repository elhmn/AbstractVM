/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModExcep.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:35:26 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/11 18:18:28 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ModExcep.class.hpp"

//constructors
ModExcep::ModExcep(void) : std::runtime_error("")
{

}

ModExcep::ModExcep(ModExcep const &rhs) : std::runtime_error("")
{
	(void)rhs;
}

//destructor
ModExcep::~ModExcep(void) throw()
{
}

//functions
const char	*ModExcep::what(void) const throw()
{
	return ("modulo by zero");
}
