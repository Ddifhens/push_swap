/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:29:11 by user              #+#    #+#             */
/*   Updated: 2025/12/13 15:12:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# define INV_PAR	2
# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <limits.h>

//node declaration
typedef struct node
{
	int				nbr;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct node		*targ;
	struct node		*next;
	struct node		*prev;
}					t_node;

//argument checking
int	invalid_digit(char *val);
int	duplicate(int val, t_node *a);

//utilities
long	ft_atol(const char *nptr);
void	ft_spiterror(t_node **stck, int ec);
t_node	*ft_nodelast(t_node *lst);
t_node	*find_max(t_node *a);
bool	issorted(t_node *stack);

//stack operations
void	init_stack(t_node **a, char **av);
void	free_stack(t_node **stck);
void	sortall(t_node **a, t_node **b);
int		stcklen(t_node *a);

//push_swap operations
//push
void	pb(t_node **b, t_node **a, bool print);
void	pa(t_node **a, t_node **b, bool print);
//swap
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
//rotate
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);
//reverse rotate
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);

#endif
