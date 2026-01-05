/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:02:20 by user              #+#    #+#             */
/*   Updated: 2025/12/13 15:12:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push(t_node **dst, t_node **src)
{
	t_node *tothis;

	if(!*src)
		return ;
	tothis = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tothis->prev = NULL;
	if (!*dst)
	{
		*dst = tothis;
		tothis->next = NULL;
	}
	else
	{
		tothis->next = *dst;
		tothis->next->prev = tothis;
		*dst = tothis;
	}
}

void	pa(t_node **a, t_node **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a, bool print)
{
	push(b, a);
	if(print)
		ft_printf("pb\n");
}
