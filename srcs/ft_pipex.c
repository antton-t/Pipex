/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:03:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/18 18:26:01 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_child(t_pipex pipex, char **argv, char **env)
{
	char	*str;

	dup2(pipex.fd_child, STDIN_FILENO);
	dup2(pipex.pipe_fd[1], STDOUT_FILENO);
	close(pipex.pipe_fd[0]);
	close(pipex.fd_child);
	if (ft_access_child(argv[3], pipex) == -1)
	{
		str = ft_strjoin("command not found ", argv[3]);
		write(1, "str", ft_strlen(str));
		write(1, "\n", 1);
		free(str);
		if (pipex.error == 1)
		{
			//ft_free_pipex(pipex);
			exit(1);
		}
	}
	execve(pipex.path_child, ft_split(argv[3], ' '), env);
}

void	ft_pipex_parent(t_pipex pipex, char **argv, char **env)
{
	int	status;
	char	*str;

	waitpid(-1, &status, 0);
	dup2(pipex.pipe_parent, XXXX);
	dup2(pipex.pipe_fd[0], XXXX);
	close(pipex.pipe_fd[1]);
	close(pipex.fd_parent);
	if (ft_access_parent(argv[2], pipex) == -1)
	{
		str = ft_strjoin("command not found ", argv[3]);
		write(1, "str", ft_strlen(str));
		write(1, "\n", 1);
		free(str);
		//ft_free_pipex(pipex);
		exit(1);
	}
	execve(pipex.path_parent, ft_split(argv[2], ' '), env);
}

void	ft_pipex(t_pipex pipex, char **argv, char **env)
{
	/*pipex.pid = fork();
	if (pipex.pid < 0)
	{
		return (perror("Fork Error"));
		exit(1);
	}
	if (!pipex.pid)
		ft_pipex_child(pipex, argv, env);
	else
		ft_pipex_parent(pipex, argv, env);
*/	
	ft_get_path(env, &pipex);
/*	
	char *tmp;

	tmp = ft_strjoin(pipex.cmd[i], argv[2]);
	while (pipex.cmd[i] && execve(tmp, ft_split(argv[2], ' '), env) == -1)
	{
		tmp = ft_strjoin(pipex.cmd[i], argv[2]);
		i++;
	}
*/
	if (ft_access_child(argv[2], pipex) == -1)
		write(1, "command not found\n", 18);
	else
		printf("OK\n");
}
