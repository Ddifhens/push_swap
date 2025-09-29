/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:38:07 by user              #+#    #+#             */
/*   Updated: 2025/09/29 18:11:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_isspace(int c)
{
	if (!c)
		return (0);
	if (!(c == 32) || (c < 9 && c > 13))
		return (0);
	else
		return (10);
}

int	checkargs(char *s1)
{
	char *p;

	p = s1;
	while (*p)
	{
		if (!(ft_isdigit(*p) && !(ft_isspace(*p))))
			return (0);
		p++;
	}
	return (1);
}
char	**ft_freeall( char **save)
{
	char	**temp;

	temp = save;
	while (1)
	{
		if (!*save)
			break ;
		free(*save);
		save++;
	}
	free(temp);
	return (NULL);
}
