#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (little[j] == big[i])
		{
			while ((i + j < len) && (big[i + j] == little[j]))
			{
				j++;
				if (!little[j])
					return ((char *)big + i);
			}
		}
		i++;
	}
	return (NULL);
}
