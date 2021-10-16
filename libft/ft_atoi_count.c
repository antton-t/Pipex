#include "libft.h"

int	ft_atoi_count(const char *nptr, int *count)
{
	int sign;
	int nb;
	char	*ptr;

	sign = 1;
	*count = 0;
	nb = 0;
	ptr = (char *) nptr;
	while (*ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\v'
		|| *ptr == '\f' || *ptr == ' ')
	{
		ptr++;
		(*count)++;
	}
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
		(*count)++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		nb = nb * 10 + (*ptr - '0');
		ptr++;
		(*count)++;
	}
	nptr = ptr;
	return (nb * sign);
}
