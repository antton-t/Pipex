/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:03:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/16 20:33:11 by eriling          ###   ########.fr       */
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
	/*pipex.pid = fork();
	if (pipex.pid < 0)
	{
		perror("Fork Error");
		exit(1);
	}
	ft_pipex_child(pipex, argv);
	ft_pipex_parent(pipex, argv);
*/struct stat buf;
	ft_look_cmd(argv, env, &pipex);
	int i = 0;
		i = 0;
	// while (pipex.cmd[i])
	// {
	// 	printf("%s\n",pipex.cmd[i]);
	// 	i++;
	// }
	i = 0;
	
	char *tmp;

	tmp = ft_strjoin(pipex.cmd[i], argv[2]);
	while (pipex.cmd[i] && execve(tmp, ft_split(argv[2], ' '), env) == -1)
	{
		tmp = ft_strjoin(pipex.cmd[i], argv[2]);
		i++;
	}
}
