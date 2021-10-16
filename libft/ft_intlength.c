int		ft_intlength(int n)
{
	int				count;

	count = 0;
	if (n == 0)
		return (1);
	count = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
