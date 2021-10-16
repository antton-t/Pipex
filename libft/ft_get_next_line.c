/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antton-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:25:01 by antton-t          #+#    #+#             */
/*   Updated: 2021/02/10 12:00:19 by antton-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_joinstr(char **str, char **buff)
{
	char *tmp;

	tmp = ft_strjoin(*str, *buff);
	*str = tmp;

}
char	*ft_get_next_line(int fd, int buffer_size)
{

	char *str = NULL;
	char *buff  = NULL;
	int	read_file;


	str = (char *)malloc(1024);
	buff = (char *)malloc(buffer_size + 1);
	if (!buff)
		return (NULL);
	read_file = 1;
	while (read_file > 0)
	{
		read_file = read(fd, buff, buffer_size);
		buff[read_file] = '\0';
		if (!*str)
			strcpy(str, buff);
		else
			ft_joinstr(&str, &buff);
	}
	free(buff);;
	return (str);
}
