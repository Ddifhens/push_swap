/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:24:22 by user              #+#    #+#             */
/*   Updated: 2025/12/13 14:38:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	reverse(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_nodelast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_node **a, bool print)
{
	reverse(a);
	if(print)
		ft_printf("rra\n");
}

void	rrb(t_node **b, bool print)
{
	reverse(b);
	if(print)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, bool print)
{
	reverse(a);
	reverse(b);
	if(print)
		ft_printf("rrr\n");
}
