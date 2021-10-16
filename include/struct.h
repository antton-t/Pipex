/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:59:18 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/16 16:44:16 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct l_pipex
{
	int	fd_parent;;
	int	fd_child;
	pid_t	pid;
	int	pipe_fd[2];
	char	**cmd;
	char	*path;

}				t_pipex;

#endif
