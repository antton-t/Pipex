/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:53:00 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:53:01 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp_lst;

	tmp_lst = NULL;
	if (lst && f)
	{
		tmp_lst = lst;
		while (tmp_lst)
		{
			f(tmp_lst->content);
			tmp_lst = tmp_lst->next;
		}
	}
}
