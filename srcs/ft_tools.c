/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:55:26 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/19 18:59:46 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_exact_path(char *cmd, t_pipex pipex)
{
	int	i;
	char	*tmp;

	i = 0;
	while (pipex.cmd[i])
	{
		tmp = ft_strjoin(pipex.cmd[i], cmd);
		if (access(tmp, F_OK) == 0)
		{
			return (tmp);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}
void	ft_execve(t_pipex pipex, char **env, char *cmd, char **argv)
{
	char	**cmd_tab;
	int	result;
	if (*cmd)
	{
		cmd_tab = ft_split(cmd, ' ');
		result = execve(ft_exact_path(cmd_tab[0], pipex), cmd_tab, env);
		if (result == -1)
		{
			perror("command not found");
			ft_free_pipex(pipex);
			exit(1);
		}
	}
	ft_free_pipex(pipex);
	exit(1);
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
