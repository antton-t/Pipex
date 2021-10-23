/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:28:02 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/22 18:01:38 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "struct.h"
# include "libft.h"

void	ft_get_path(char **env, t_pipex *pipex);
void	ft_execve(t_pipex pipex, char **cmd);
void	ft_free_pipex(t_pipex pipex);
void	ft_pipex_child(t_pipex pipex, char **argv, int pipe_fd);
void	ft_pipex_parent(t_pipex pipex, char **argv, int pipe_fd);
void	ft_free_cmd(char **str);
#endif
