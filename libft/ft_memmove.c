/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:54:13 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:54:15 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	ol;

	ol = 0;
	i = 0;
	while (i < len)
	{
		if (dst == src + i)
			ol = i;
		i++;
	}
	if (ol == 0)
		return (ft_memcpy(dst, src, len));
	i = 0;
	while (i < len)
	{
		*(char *)(dst + len - 1 - i) = *(char *)(src + len - 1 - i);
		i++;
	}
	return (dst);
}
