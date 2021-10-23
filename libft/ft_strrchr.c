/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:59:49 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:59:50 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		l;
	char	*p;

	l = ft_strlen(s);
	p = NULL;
	i = 0;
	while (i < l + 1)
	{
		if (s[i] == (char)c)
			p = (char *)s + i;
		i++;
	}
	return (p);
}
