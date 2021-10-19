/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:18:06 by antton-t          #+#    #+#             */
/*   Updated: 2021/10/18 16:57:21 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	ft_error(void)
{
	printf("./Pipex errOr execution\n");
	exit(1);
}
int	main(int argc, char ** argv, char ** env)
{
	t_pipex	pipex;
	char	*str;

	if (argc == 5)
	{
		pipex.fd_parent = open(argv[1], O_RDONLY);
		pipex.fd_child = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex.fd_parent < 0 || pipex.fd_child < 0)
		{
			str = ft_strjoin("no such file or directory ", argv[1]);
			write(1, str, ft_strlen(str));
			write(1, "\n", 1);
			pipex.error = 1;
			free(str);
		}
		pipe(pipex.pipe_fd);
		ft_pipex(pipex, argv, env);
	}
	else
		ft_error();

	return (0);
}
