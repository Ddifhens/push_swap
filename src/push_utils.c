/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:38:07 by user              #+#    #+#             */
/*   Updated: 2025/12/19 15:00:32 by user             ###   ########.fr       */
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
