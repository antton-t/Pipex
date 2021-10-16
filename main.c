/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:18:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/16 19:00:36 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	ft_open_error(void)
{
	write(1, "Error in file\n", 14);
	exit(1);
}
void	ft_error(void)
{
	printf("./Pipex errOr execution\n");
	exit(1);
}
int	main(int argc, char ** argv, char ** env)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		pipex.fd_parent = open(argv[1], O_RDONLY);
		pipex.fd_child = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex.fd_parent < 0 || pipex.fd_child < 0)
			ft_open_error();
		pipe(pipex.pipe_fd);
		ft_pipex(pipex, argv, env);
	}
	else
		ft_error();

	return (0);
}
