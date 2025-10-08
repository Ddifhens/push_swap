/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:29:11 by user              #+#    #+#             */
/*   Updated: 2025/09/29 17:54:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# define INV_PAR	2
# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

char	**ft_freeall( char **save);
int	checkargs(char *s1);
void	ft_sort_int_tab(int *tab, unsigned int size);
int		ft_wordcount(char const *str, char sep);

#endif
