/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:06:42 by user              #+#    #+#             */
/*   Updated: 2026/01/05 20:38:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rotate(t_node **a)
{
	t_node	*pointer;

	if (!a || !(*a)->next)
		return ;
	pointer = ft_nodelast(*a);
	pointer->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	pointer->next->prev = pointer;
	pointer->next->next = NULL;
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

void	ra(t_node **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_node **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}
