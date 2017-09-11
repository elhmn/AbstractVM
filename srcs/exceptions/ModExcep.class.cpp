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
ModExcep::ModExcep(void)
{
}

ModExcep::ModExcep(ModExcep const &rhs)
{
	(void)rhs;
}

//destructor
ModExcep::~ModExcep(void) throw()
{
}

//functions
// const char	*ModExcep::what(void) throw()
// {
// 	return ("wrong modulo operand");
// }
