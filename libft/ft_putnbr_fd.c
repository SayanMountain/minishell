#include "libft.h"

void	ft_putnbr_fd(int c, int fd)
{
	char	i;

	if (c == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (c < 0)
	{
		write(fd, "-", 1);
		c *= -1;
	}
	if (c > 9)
		ft_putnbr_fd(c / 10, fd);
	i = (c % 10) + '0';
	if (ft_isdigit(i) == 1)
		write(fd, &i, 1);
}
