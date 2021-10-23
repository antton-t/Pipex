/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_type_uint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:55:00 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:55:03 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printuint2(int l, t_form *info, unsigned int n)
{
	int	just;

	if (info->prec > l)
		just = info->just - info->prec;
	else
		just = info->just - l;
	if (info->flag & FLAG_MIN)
	{
		ft_doingjust(info->prec - l, '0');
		if (l != 0 || n != 0)
			ft_putnbr_fd(n, 1);
		ft_doingjust(just, ' ');
	}
	else if (info->flag & FLAG_ZERO)
	{
		ft_doingjust(just, '0');
		ft_putnbr_fd(n, 1);
	}
	else
	{
		ft_doingjust(just, ' ');
		ft_doingjust(info->prec - l, '0');
		if (l != 0 || n != 0)
			ft_putnbr_fd(n, 1);
	}
}

static int	ft_returnuint(t_form *info, int l)
{
	int	r;

	r = l;
	if (info->prec > r)
		r = info->prec;
	if (info->just > r)
		r = info->just;
	return (r);
}

int	ft_printuint(t_form *info, va_list args)
{
	unsigned int	n;
	unsigned int	aux;
	int				l;

	n = va_arg(args, unsigned int);
	l = 1;
	aux = n / 10;
	while (aux != 0)
	{
		aux = aux / 10;
		l++;
	}
	if (info->flag & FLAG_DOT && n == 0 && info->prec == 0)
		l = 0;
	if (info->flag & FLAG_ZERO && info->flag & FLAG_DOT)
		info->flag &= (~FLAG_ZERO);
	ft_printuint2(l, info, n);
	return (ft_returnuint(info, l));
}
