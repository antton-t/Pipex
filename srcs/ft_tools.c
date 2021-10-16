/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:55:26 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/16 19:05:38 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_cmd(char *str, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (*str != '/')
		str++;
	pipex->cmd = ft_split(str, ':');
	while (pipex->cmd[i])
	{
		pipex->cmd[i] = ft_strjoin(pipex->cmd[i], "/");
		i++;
	}
}

void	ft_look_cmd(char **argv, char **env, t_pipex *pipex)
{
	int	i;
	char	*str;

	i = 0;
	(void)argv;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
				env[i][3] ==  'H' && env[i][4] == '=')
		{
			str = env[i];
			ft_get_cmd(str, pipex);
		}
			i++;
	}
}
