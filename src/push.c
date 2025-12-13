/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:03:24 by user              #+#    #+#             */
/*   Updated: 2025/12/13 14:49:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

bool	issorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->next->nbr < stack->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_len(t_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
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

int main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (write(2, "Error\n", 6), 1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av);
	if (!issorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		if (stack_len(a) == 3)
			sorthree(&a);
		else
			sortall(&a,&b);
	}
	free_stack(&a);
	return (0) ;
}
