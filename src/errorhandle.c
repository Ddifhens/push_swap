/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:15:46 by user              #+#    #+#             */
/*   Updated: 2025/12/08 12:19:53 by user             ###   ########.fr       */
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

int	duplicate(int val, t_node *a)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == val)
			return (write(2, "Error\n", 6), 1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_node **stck)
{
	t_node	*tmp;
	t_node	*pointer;

	if (!stck)
		return;
	pointer = *stck;
	while(pointer)
	{
		tmp = pointer->next;
		pointer->nbr = 0;
		free(pointer);
		pointer = tmp;
	}
	*stck = NULL;
}

void	ft_spiterror(t_node **stck, int ec)
{
	free_stack(stck);
	if (ec == 1)
		ft_printf("Allocation ");
	if (ec == 2)
		ft_printf("No stack ");
	if (ec == 3)
		ft_printf("Invalid parameters ");
	ft_printf("Error\n");
	exit(1);
}
