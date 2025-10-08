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
	char	a;

	a = c;
	if ((a == 32) || (c <= 9 && c >= 13))
		return (10);
	else
		return (0);
}

int	checkargs(char *s1)
{
	char *p;

	p = s1;
	while (*p)
	{
		if (*p == '-')
			p++;
		if (((ft_isdigit(*p)) == 0) && ((ft_isspace(*p)) == 0))
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

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
		i++;
	}
}

int		ft_wordcount(char const *str, char sep)
{
	int i;
	int count;

	if (str == 0 || str[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (str[0] != sep)
		count++;
	while (str[i] != '\0')
	{
		if (str[i] != sep && str[i - 1] == sep)
			count++;
		i++;
	}
	return (count);
}
