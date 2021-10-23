/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:49:03 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/22 19:17:33 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
}

void	ft_free_cmd(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
