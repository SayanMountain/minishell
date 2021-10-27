#include "libft.h"

void	ft_putstr_fd(const char *c, int fd)
{
	int	i;

	i = 0;
	if (!c || fd < 0)
		return ;
	while (c[i])
	{
		ft_putchar_fd(c[i], fd);
		i++;
	}
}
