/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:59:31 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:59:33 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	l;

	l = ft_strlen(needle);
	i = 0;
	j = 0;
	while (haystack[i] && i < n && j < l)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < n && haystack[i + j])
			j++;
		i++;
	}
	if (l == 0)
		return ((char *)haystack);
	if (j == l)
		return ((char *)haystack + i - 1);
	return (NULL);
}
