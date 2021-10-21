/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:18:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/21 11:29:25 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	ft_error(void)
{
	printf("error pipex\n");
	exit(1);
}
int	main(int argc, char ** argv, char ** env)
{
	t_pipex	pipex;

	if (argc == 5 || pipe(pipex.pipe_fd) >= 0)
	{
		pipex.fd_child = open(argv[1], O_RDONLY);
		if (pipex.fd_child < 0)
		{
			close(pipex.fd_parent);
			write(1, "No such file or directory\n", 26);
			exit(1);
		}
		ft_pipex(pipex, argv, env);
	}
	else
		ft_error();
	return (0);
}
