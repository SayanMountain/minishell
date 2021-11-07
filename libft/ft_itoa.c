#include "libft.h"

static int	isnegative(int n)
{
	int		i;
	int		negative;

	i = 1;
	negative = 0;
	if (n < 0)
	{
		n *= -1;
		negative = 1;
	}
	return (negative);
}

static int	len(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		i;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = isnegative(n);
	if (n < 0)
		n *= -1;
	i = len(n) + neg;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[i] = n + '0';
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	if (neg == 1)
		str[i] = '-';
	return (str);
}
