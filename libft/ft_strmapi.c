/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:59:14 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:59:16 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*sol;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	sol = (char *)ft_calloc(sizeof(char), (l + 1));
	if (sol == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		sol[i] = f(i, s[i]);
		i++;
	}
	return (sol);
}
