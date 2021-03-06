/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:58:42 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:58:44 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	l = ft_strlen(src);
	i = 0;
	if (l == 0)
		dst[i] = src[i];
	while (i < dstsize - 1 && i < ft_strlen(src) && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (i > 0 && ft_strlen(src) > 0)
		dst[i] = 0;
	return (l);
}
