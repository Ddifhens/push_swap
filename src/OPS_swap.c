/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:21:53 by user              #+#    #+#             */
/*   Updated: 2025/12/13 14:38:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap(t_node **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_node **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_node **b, bool print)
{
	swap(b);
	if (print)
		ft_printf ("sb\n");
}

void	ss(t_node **a, t_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}

