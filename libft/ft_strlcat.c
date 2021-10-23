/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:58:27 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:58:29 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	l = ft_strlen(dst);
	i = 0;
	while (l + i < dstsize - 1 && src[i] && dstsize != 0)
	{
		dst[l + i] = src[i];
		i++;
	}
	if (i > 0)
		dst[l + i] = 0;
	if (l <= dstsize)
		return (l + ft_strlen(src));
	else
		return (ft_strlen(src) + dstsize);
}
