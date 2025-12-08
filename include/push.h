/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:29:11 by user              #+#    #+#             */
/*   Updated: 2025/12/08 12:19:39 by user             ###   ########.fr       */
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

//stack operations
void	init_stack(t_node **a, char **av);

#endif
