#include "libft.h"

int	ft_atoi(const char *s)
{
	int			i;
	long long	sign;
	long long	n;

	i = 0;
	sign = 1;
	n = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] && ft_isdigit(s[i]) == 1)
	{
		n = (n * 10) + (s[i++] - 48);
		if ((n * sign) < -2147483648)
			return (0);
		if ((n * sign) > 2147483647)
			return (-1);
	}
	return (n * sign);
}
