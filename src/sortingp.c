/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:02:31 by user              #+#    #+#             */
/*   Updated: 2025/12/19 14:21:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
		if (index >= mid)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		index++;
	}
}

void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_node;
	t_node	*target;
	long	match;

	while (a)
	{
		match = LONG_MIN;
		current_node = b;
		while (current_node)
		{
			if (current_node->nbr > a->nbr && current_node->nbr < match)
			{
				match = current_node->nbr;
				target = current_node;
			}
			current_node = current_node->next;
		}
		if (match == LONG_MIN)
			a->targ = find_max(b);
		else
			a->targ = target;
		a = a->next;
	}
}

void	cost_a(t_node *a, t_node *b)
{
	int	alen;
	int	blen;

	alen = stcklen(a);
	blen = stcklen(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = alen - (a->index);
		if (a->targ->above_median)
			a->cost += a->targ->index;
		else
			a->cost += blen - (a->targ->index);
		a = a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long	cheapval;
	t_node	*cheapnode;

	if (!stack)
		return ;
	cheapval = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapval)
		{
			cheapval = stack->cost;
			cheapnode = stack;
		}
		stack = stack->next;
	}
	cheapnode->cheapest = true;
}

void	init_nodes_a(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_a(a, b);
	set_cheapest(a);
}
