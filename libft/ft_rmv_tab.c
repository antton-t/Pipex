#include "libft.h"

char	*ft_rmv_tab(char *str)
{
	char	*out;
	size_t	i;
	size_t	j;
	size_t	space;

	space = 0;
	i = 0;
	j = 0;
	if (!(out = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{	out[j] = str[i];
			i++;
			j++;
			space = 1;
		}
		else if ((str[i] == ' '  || str[i] == '\t') &&  space == 1)
		{
			out[j] = ' ';
			i++;
			j++;
			space = 0;
		}
		else
			i++;
	}
	while (j <  ft_strlen(str))
	{
		out[j] = 0;
		j++;
	}
	return (out);
}
