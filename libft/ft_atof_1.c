#include "libft.h"

double	ft_get_deci_1(char **ptr)
{
	double	deci;
	double	div;

	div = 1;
	deci = 0;
	if (**ptr == '.' || **ptr == ',')
		(*ptr)++;
	while (**ptr >= '0' && **ptr <= '9')
	{
		deci = (deci * 10) + (**ptr - '0');
		div *= 10;
		(*ptr)++;
	}
	return (deci / div);
}
double	ft_atof_1(char **str)
{
	int	sign;
	double	entier;
	double	deci;

	sign = 1;
	entier = 0;
	deci = 0;
	while (**str == ' ')
		(*str)++;
	if (**str ==  '-'  || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (**str >= '0'  && **str <= '9' && *str)
	{
		entier = (entier * 10) + (**str - '0');
		(*str)++;
	}
	if (**str == '.')
		deci = ft_get_deci_1(str);
	return (sign * (entier + deci));
}
