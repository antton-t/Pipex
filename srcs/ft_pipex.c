/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:03:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/19 19:25:21 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_child(t_pipex pipex, char *cmd, char **env, char **argv)
{
	char	*str;
	char	**cmd_final;

	cmd_final = ft_split(cmd, ' ');
	pipex.fd_child = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
//	dup2(pipex.fd_child, STDIN_FILENO);
	dup2(pipex.pipe_fd[1], STDOUT_FILENO);
	close(pipex.pipe_fd[0]);
	close(pipex.fd_child);
//	if (execve(ft_exec_path(pipex, cmd), cmd_final, env) == -1)
	{
		str = ft_strjoin("command not found ", "\n");
		write(1, "str", ft_strlen(str));
		free(str);
		if (pipex.error == 1)
		{
			//ft_free_pipex(pipex);
			exit(1);
		}
	}
//	execve(pipex.path_child, ft_split(argv[3], ' '), env);
}

void	ft_pipex_parent(t_pipex pipex, char **argv, char **env)
{
	int	status;
	char	*str;

	dup2(pipex.pipe_fd[0], STDIN_FILENO);
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
//	execve(pipex.path_parent, ft_split(argv[2], ' '), env);
}

void	ft_pipex(t_pipex pipex, char **argv, char **env)
{
//	pipex.pid = fork();
	ft_get_path(env, &pipex);
/*	if (pipex.pid < 0)
	{
		return (perror("Fork Error"));
		//ft_free_pipex(pipex);
		exit(1);
	}
	if (pipex.pid == 0)
		ft_pipex_child(pipex, argv[3], env, argv);
	else
		ft_pipex_parent(pipex, argv[2], env);
*/
}
