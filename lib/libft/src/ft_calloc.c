/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormanue <jormanue@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:09:42 by jormanue          #+#    #+#             */
/*   Updated: 2025/04/16 18:22:44 by jormanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	mult;

	if (nmemb != 0 && size != 0 && (nmemb > ((size_t)-1 / size)))
		return (NULL);
	mult = nmemb * size;
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, mult);
	return (arr);
}
