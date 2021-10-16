#include "libft.h"

int	ft_atoi_1(char **nptr)
{
	int sign;
	int nb;
	char	*ptr;

	sign = 1;
	nb = 0;
	ptr = *nptr;
	while (*ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\v'
		|| *ptr == '\f' || *ptr == ' ')
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		nb = nb * 10 + (*ptr - '0');
		ptr++;
	}
	*nptr = ptr;
	return (nb * sign);
}
