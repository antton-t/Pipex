/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:49:55 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:49:57 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;
	size_t	i;

	pt = (void *)malloc(size * count);
	if (pt == NULL)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		*(char *)(pt + i) = 0;
		i++;
	}
	return (pt);
}
