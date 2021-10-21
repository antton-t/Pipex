#include "pipex.h"

void	ft_free_pipex(t_pipex pipex)
{
	int	i;

	i = 0;
	if (pipex.cmd != NULL)
	{
		while (pipex.cmd[i])
		{
			free(pipex.cmd[i]);
			i++;	
		}
		free(pipex.cmd);
	}
	return ;
}
