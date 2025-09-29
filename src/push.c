/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:03:24 by user              #+#    #+#             */
/*   Updated: 2025/09/29 16:21:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	*makenbrs(char *args)
{
	char	**list;
	int		**nbr;
	int		size;
	char	*l_ptr;
	int		*n_ptr;

	size = ft_strlen(args);
	list = ft_split(args, size);
	nbr = ft_calloc(size, sizeof (int *));
	n_ptr = *nbr;
	l_ptr = *list;
	while(*list)
		*n_ptr++ = ft_atoi((const char)*l_ptr++);

}

int main(int argc, char **argv)
{
	int	*nbrs;
	int	i;

	i = 0;
	if (argc < 2)
		return (write(2,"ERROR\n", 6), INV_PAR);
	nbrs = makenbrs(argv[1]);
	while (i < (ft_strlen(nbrs)))
		ft_printf("%d", nbrs[i++]);
}
