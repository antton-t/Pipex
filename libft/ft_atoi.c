/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <antton-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:00:30 by antton-t          #+#    #+#             */
/*   Updated: 2020/04/29 16:00:32 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int sign;
	int nb;
	char	*ptr;

	sign = 1;
	nb = 0;
	ptr = (char *) nptr;
	while (*ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\v'
		|| *ptr == '\f' || *ptr == ' ')
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		nb = nb * 10 + (*ptr - '0');
		ptr++;
	}
	nptr = ptr;
	return (nb * sign);
}
