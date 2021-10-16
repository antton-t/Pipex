/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:03:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/16 17:12:17 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_child(t_pipex pipex, char **argv)
{
}

void	ft_pipex_parent(t_pipex pipex, char **argv)
{
}

void	ft_pipex(t_pipex pipex, char **argv, char **env)
{
	ft_pipex_child(pipex, argv);
	ft_pipex_parent(pipex, argv);
	pipex.pid = fork();
	if (pipex.pid < 0)
	{
		perror("Fork Error");
		exit(1);
	}
}
