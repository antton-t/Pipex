/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:59:18 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/18 16:45:07 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct l_pipex
{
	int	fd_parent;
	int	fd_child;
	pid_t	pid;
	int	pipe_fd[2];
	char	**cmd;
	char	*path_child;
	char	*path_parent;
	int	error;
}				t_pipex;

#endif
