/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:39:28 by user              #+#    #+#             */
/*   Updated: 2025/12/19 15:00:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*current;
	t_node	*target;
	long	match;

	while(b)
	{
		match = LONG_MAX;
		current = a;
		while(current)
		{
			if (current->nbr > b->nbr && current->nbr < match)
			{
				match = current->nbr;
				target = current;
			}
			current = current->next;
		}
		if (match == LONG_MAX)
			b->targ = find_min(a);
		else
			b->targ = target;
		b = b->next;
	}
}

void	move_b_to_a(t_node **a, t_node **b)
{
	preppush(a, ((*b)->targ), 'a');
	pa(a, b, true);
}

void	min_on_top(t_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

void	init_nodes_b(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
