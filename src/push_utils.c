/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:38:07 by user              #+#    #+#             */
/*   Updated: 2026/01/05 20:48:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_node	*find_min(t_node *stack)
{
	long	min;
	t_node	*found;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			found = stack;
		}
		stack = stack->next;
	}
	return (found);
}


t_node	*find_max(t_node *a)
{
	long	max;
	t_node	*pointer;

	if (!a)
		return (NULL);
	max = LONG_MIN;
	while (a)
	{
		if (a->nbr > max)
		{
			max = a->nbr;
			pointer = a;
		}
		a = a->next;
	}
	return (pointer);
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack =stack->next;
	}
	return (NULL);
}

int	stcklen(t_node *a)
{
	int i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

bool	issorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->next->nbr < stack->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

