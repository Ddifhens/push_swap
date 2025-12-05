/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:15:46 by user              #+#    #+#             */
/*   Updated: 2025/12/05 16:50:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	invalid_digit(char *val)
{
	if (!(*val == '+' || *val == '-' || (ft_isdigit(*val))))
		return (write(2, "Error\n", 6), 1);
	if ((*val == '+' || *val == '-') && !(ft_isdigit(val[1])))
		return (write(2, "Error\n", 6), 1);
	while (*++val)
		if (!(ft_isdigit(*val)))
			return (write(2, "Error\n", 6), 1);
	return (0);
}

int	duplicate(int *val, t_node *a)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == *val)
			return (write(2, "Error\n", 6), 1);
		a = a->next;
	}
	return (0);
}
