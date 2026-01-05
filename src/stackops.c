/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:53:49 by user              #+#    #+#             */
/*   Updated: 2025/12/19 14:52:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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

void	rotate_both(t_node **a, t_node **b, t_node *cheapest, bool rev)
{
	while (*b != cheapest->targ && *a != cheapest)
	{
		if (rev)
			rrr(a, b, true);
		else
			rr(a, b, true);
	}
	current_index(*a);
	current_index(*b);
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

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->targ->above_median)
		rotate_both(a, b, cheapest, false);
	else if (!(cheapest->above_median) && !(cheapest->targ->above_median))
			rotate_both(a, b, cheapest, true);
	preppush(a, cheapest, 'a');
	preppush(b, cheapest->targ, 'b');
	pb(b, a, true);
}
