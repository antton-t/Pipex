/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:55:26 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/22 19:18:17 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/libft.h"

char	*ft_exact_path(char *cmd, t_pipex pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	while (pipex.cmd[i])
	{
		tmp = ft_strjoin(pipex.cmd[i], cmd);
		if (access(tmp, F_OK) == 0)
		{
			return (tmp);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

void	ft_execve(t_pipex pipex, char **cmd)
{
	int		result;

	result = execve(ft_exact_path(cmd[0], pipex), cmd, NULL);
	if (result == -1)
	{
		perror("command not found");
	}
	ft_free_cmd(cmd);
	ft_free_pipex(pipex);
	exit(1);
}

void	ft_get_cmd(char *str, t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	while (*str != '/')
		str++;
	pipex->cmd = ft_split(str, ':');
	while (pipex->cmd[i])
	{
		tmp = pipex->cmd[i];
		pipex->cmd[i] = ft_strjoin(pipex->cmd[i], "/");
		free(tmp);
		i++;
	}
}

void	ft_get_path(char **env, t_pipex *pipex)
{
	int		i;
	char	*str;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
				env[i][3] == 'H' && env[i][4] == '=')
		{
			str = env[i];
			ft_get_cmd(str, pipex);
		}
		i++;
	}
}
