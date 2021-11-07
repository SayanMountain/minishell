#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	dst = (void *)malloc(count * size);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}
