/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:51:30 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:51:32 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				i;
	int				l;
	unsigned int	sup;
	char			*s;

	l = ft_lengthnumb(n);
	s = (char *)ft_calloc(sizeof(char), l + 1);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		sup = -1 * n;
	}
	else
		sup = n;
	i = 1;
	while (i <= l && s[l - i] != '-')
	{
		s[l - i] = sup % 10 + 48;
		sup = sup / 10;
		i++;
	}
	return (s);
}
