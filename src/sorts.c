/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:37:40 by user              #+#    #+#             */
/*   Updated: 2026/01/05 20:39:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sortall(t_node **a, t_node **b)
{
	int	len;

	len = stcklen(*a);
	if (len-- > 3 && !(issorted(*a)))
		pb(b, a, true);
	if (len-- > 3 && !(issorted(*a)))
		pb(b, a, true);
	while (len-- > 3 && !(issorted(*a)))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sorthree(a);
	while(*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	sorthree(t_node **a)
{
	t_node	*max;

	max = find_max(*a);
	if (max == *a)
		ra(a, true);
	else if ((*a)->next == max)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}

