/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:51:58 by antton-t          #+#    #+#             */
/*   Updated: 2021/09/23 19:52:00 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_list;

	if (*lst && del)
	{
		while (*lst)
		{
			del((*lst)->content);
			tmp_list = *lst;
			*lst = (*lst)->next;
			free(tmp_list);
		}
		lst = NULL;
	}
}
