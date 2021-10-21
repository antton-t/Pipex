/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:03:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/21 11:48:32 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_parent(t_pipex pipex, char *cmd, char **env, char **argv)
{
	pipex.fd_parent = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.fd_parent >= 0)
	{
		dup2(pipex.pipe_fd[0], STDIN_FILENO);
		close(pipex.pipe_fd[0]);
		dup2(pipex.fd_parent, STDOUT_FILENO);
		close(pipex.fd_parent);
		ft_execve(pipex, env, cmd, argv);
	}
	else
	{
		ft_free_pipex(pipex);
		exit(1);
	}
}

void	ft_pipex_child(t_pipex pipex, char *cmd, char **env, char **argv)
{
	dup2(pipex.fd_child, STDIN_FILENO);
	close(pipex.fd_child);
	dup2(pipex.pipe_fd[1], STDOUT_FILENO);
	close(pipex.pipe_fd[1]);
	ft_execve(pipex, env, cmd, argv);
}

void	ft_pipex(t_pipex pipex, char **argv, char **env)
{
	ft_get_path(env, &pipex);
	if (fork() == 0)
	{
		close(pipex.pipe_fd[0]);
		ft_pipex_child(pipex, argv[2], env, argv);
	}
	else
	{
		close(pipex.pipe_fd[1]);
		ft_pipex_parent(pipex, argv[3], env, argv);
	}
}
