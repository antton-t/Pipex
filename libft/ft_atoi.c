/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:18:53 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:18:55 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sig;
	long	n;

	i = 0;
	sig = 1;
	n = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1 * sig;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + (str[i++] - 48);
		if (n < 0 && sig == -1)
			return (0);
		if (n < 0 && sig == 1)
			return (-1);
	}
	return (sig * n);
}
