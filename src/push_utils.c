/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:38:07 by user              #+#    #+#             */
/*   Updated: 2025/12/05 17:32:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	init_stack(t_node **a, char **av)
{
	long	x;
	int		i;

	i = 0;
	while (av[i])
	{
		if ((invalid_digit(av[i]))
			//call function to properly handle stack errors
		x = ft_atol(av[i]);	
		if(duplicate(av[i], (int)x))
			//call function to properly handle stack errors

	// for all values of av[i]
	//check proper int values formatting and size 
	//check for duplicates
	//
	//for each proper value use functions to create new node, 
	//assign proper value and append it to the end of a
	}
}
