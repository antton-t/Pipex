/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:18:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/22 19:19:15 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/pipex.h"

void	ft_directory(void)
{
	write(1, "Pipex error\n", 12);
	exit(1);
}

int	ft_check(char **argv)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (argv[2][i])
	{
		if (argv[2][i] != ' ' && argv[2][i] != '\t')
			count = 1;
		i++;
	}
	i = 0;
	while (argv[3][i])
	{
		if ((argv[3][i] != ' ' && argv[3][i] != '\t') && count == 1)
			count = 2;
		i++;
	}
	return (count);
}

void	ft_fork_error(t_pipex pipex)
{
	ft_free_pipex(pipex);
	write(1, "fork error\n", 11);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		pid;

	pipex.fd_parent = open(argv[1], O_RDONLY);
	pipex.fd_child = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	pid = ft_check(argv);
	if (argc != 5 || pipe(pipex.pipe_fd) || pipex.fd_parent < 0
		|| pipex.fd_child < 0 || pid != 2)
		ft_directory();
	pid = fork();
	if (pid == -1)
		ft_fork_error(pipex);
	ft_get_path(env, &pipex);
	if (pid == 0)
	{
		close(pipex.pipe_fd[0]);
		ft_pipex_parent(pipex, argv, pipex.pipe_fd[1]);
	}
	else
	{
		close(pipex.pipe_fd[1]);
		ft_pipex_child(pipex, argv, pipex.pipe_fd[0]);
	}
	ft_free_pipex(pipex);
}
