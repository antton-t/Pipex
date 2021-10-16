/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:28:02 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/16 18:54:04 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include "libft.h"

void	ft_pipex(t_pipex pipex, char **argv, char **env);
void	ft_look_cmd(char **argv, char **env, t_pipex *pipex);
void	ft_pipex(t_pipex pipex, char **argv, char **env);
