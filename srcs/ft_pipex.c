/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:03:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/22 19:17:55 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_pipex_parent(t_pipex pipex, char **argv, int pipe_fd)
{
	char	**tmp_parent;

	tmp_parent = ft_split(argv[2], ' ');
	dup2(pipex.fd_parent, STDIN_FILENO);
	close(pipex.fd_parent);
	dup2(pipe_fd, STDOUT_FILENO);
	close(pipe_fd);
	ft_execve(pipex, tmp_parent);
	ft_free_cmd(tmp_parent);
}

void	ft_pipex_child(t_pipex pipex, char **argv, int pipe_fd)
{
	char	**tmp_child;

	tmp_child = ft_split(argv[3], ' ');
	dup2(pipe_fd, STDIN_FILENO);
	close(pipe_fd);
	dup2(pipex.fd_child, STDOUT_FILENO);
	close(pipex.fd_child);
	ft_execve(pipex, tmp_child);
	ft_free_cmd(tmp_child);
}
