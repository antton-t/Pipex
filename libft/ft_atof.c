#include "libft.h"

double	ft_get_deci(char **ptr, int *count)
{
	double	deci;
	double	div;

	div = 1;
	deci = 0;
	*count = 0;
	if (**ptr == '.' || **ptr == ',')
	{	(*ptr)++;
		(*count)++;
	}
	while (**ptr >= '0' && **ptr <= '9')
	{
		deci = (deci * 10) + (**ptr - '0');
		div *= 10;
		(*count)++;
		(*ptr)++;
	}
	return (deci / div);
}
double	ft_atof(char *str, int *str_length)
{
	int	sign;
	char	*ptr;
	double	entier;
	double	deci;
	int	count;

	sign = 1;
	ptr = str;
	entier = 0;
	deci = 0;
	count = 0;
	while (*ptr == ' ')
		ptr++;
	if (*ptr ==  '-'  || *ptr == '+')
	{
		if (*ptr == '-')
		{
			sign = -1;
			(*str_length)++;
		}
		ptr++;
	}
	while (*ptr >= '0'  && *ptr <= '9' && *ptr)
	{
		entier = (entier * 10) + (*ptr - '0');
		ptr++;
		(*str_length)++;
	}
	if (*ptr == '.')
		deci = ft_get_deci(&ptr, &count);
	*str_length += count;
	return (sign * (entier + deci));
}
