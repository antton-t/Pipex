/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:54:34 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:54:36 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnotthetype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

int	ft_isnothing(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || ft_isdigit(c) || c == '-'
		|| c == '.' || c == '*' || c == '%')
		return (1);
	return (0);
}

void	ft_doingjust(int just, char c)
{
	int	i;

	i = 0;
	while (i < just)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}

void	ft_suport(int *i, const char **format)
{
	(*i)++;
	(*format)++;
}
