#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (unsigned char)c != ((unsigned char *)s)[i])
		i++;
	if (i == n)
		return (NULL);
	return ((void *)s + i);
}
