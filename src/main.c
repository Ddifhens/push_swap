/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42school.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:03:24 by user              #+#    #+#             */
/*   Updated: 2026/01/05 20:48:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

char	**createparams(char **av, int ac)
{
	char	*str;
	char	*space;
	char	*ptr;
	int		i;
	char	**sstr;

	space = " ";
	str = "\0";
	i = 1;
	while (ac)
	{
		ptr = str;
		str = ft_strjoin("", av[i++]);
		if (*ptr)
			free(ptr);
		ptr = str;
		str = ft_strjoin(str, space);
		if (*ptr)
			free(ptr);
		ac--;
	}
	sstr = ft_split(str, ' ');
	free(str);
	return (sstr);
}

int main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (write(2, "Error\n", 6), 1);
	else if (ac >= 2)
		av = createparams(av, ac - 1);
	init_stack(&a, av);
	if (!issorted(a))
	{
		if (stcklen(a) == 2)
			sa(&a, true);
		if (stcklen(a) == 3)
			sorthree(&a);
		else
			sortall(&a,&b);
	}
	free_stack(&a);
	free_chars(av);
	return (0) ;
}
