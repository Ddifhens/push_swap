/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:03:24 by user              #+#    #+#             */
/*   Updated: 2025/09/29 18:08:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	*makenbrs(char *args)
{
	int		*a;
	char	**list;
	int		*a_p;

	a = ft_calloc(2, sizeof (int));
	a_p = a;
	list = ft_split(args, 32);
	while (*list)
	{
		*a++ = (ft_atoi(*list++));
	}
	return(a_p);
}

int main(int argc, char **argv)
{
	int	*args;

	if (argc != 2 || (checkargs(argv[1])) == 0)
		return (write(2,"ERROR\n", 6), INV_PAR);
	args = makenbrs(argv[1]);
	while (*args)
		ft_printf("%d\n", *args++);
}
