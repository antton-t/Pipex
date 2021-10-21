/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:49:03 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/21 11:50:57 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_pipex(t_pipex pipex)
{
	int	i;

	i = 0;
	if (pipex.cmd != NULL)
	{
		while (pipex.cmd[i])
		{
			free(pipex.cmd[i]);
			i++;
		}
		free(pipex.cmd);
	}
	return ;
}
