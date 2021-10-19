/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:55:26 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/18 14:25:36 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_access_parent(char *argv, t_pipex pipex)
{
	int i;
	char *tmp;

	i = 0;
	while (pipex.cmd[i])
	{
		tmp = ft_strjoin(pipex.cmd[i], argv);
		if (access(tmp, F_OK | X_OK) != -1)
		{
			pipex.path_parent = tmp;;
			return (1);
		}
		else
		{
			free(tmp);
			i++;
		}
	}
	return (-1);
}

int	ft_access_child(char *argv, t_pipex pipex)
{
	int i;
	char *tmp;

	i = 0;
	while (pipex.cmd[i])
	{
		tmp = ft_strjoin(pipex.cmd[i], argv);
		if (access(tmp, F_OK | X_OK) != -1)
		{
			pipex.path_child = tmp;;
			return (1);
		}
		else
		{
			free(tmp);
			i++;
		}
	}
	return (-1);
}

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

void	ft_get_path(char **env, t_pipex *pipex)
{
	int	i;
	char	*str;

	i = 0;
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
