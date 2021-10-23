/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:54:19 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:54:20 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	a;
	size_t	i;

	a = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*((unsigned char *)(b + i)) = a;
		i++;
	}
	return (b);
}
