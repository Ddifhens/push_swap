/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:32:46 by user              #+#    #+#             */
/*   Updated: 2026/01/05 20:45:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	append_node(t_node **stck, int n)
{
	t_node *new;
	t_node *tmp;

	if (!stck)
		return ;
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->next = NULL;
	new->nbr = n;
	new->cheapest = 0;
	if (!(*stck))
	{
		*stck = new;
		new->prev = NULL;
	}
	else
	{
		tmp = ft_nodelast(*stck);
		tmp->next = new;
		new->prev = tmp;
	}
}

void	init_stack(t_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if ((invalid_digit(av[i])))
			ft_spiterror(a, 3);
		n = ft_atol(av[i]);	
		if (n > INT_MAX || n < INT_MIN)
			ft_spiterror(a, 3);
		if(duplicate((int)n, *a))
			ft_spiterror(a, 3);
		append_node(a, (int)n);
		i++;
	}
}

void	preppush(t_node **stack, t_node *node, char name)
{
	while (*stack != node)
	{
		if (name == 'a')
		{
			if (node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if( name == 'b')
		{
			if (node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

void	current_index(t_node *a)
{
	int	mid;
	int index;

	index = 0;
	if (!a)
		return ;
	mid = (stcklen(a)) / 2;
	while (a)
	{
		a->index = index;
		if (index <= mid)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		index++;
	}
}
