#include "libft.h"

size_t	ft_strlcpy(char *str1, const char *str2, size_t size)
{
	size_t	i;

	i = 0;
	if (!str2)
		return (0);
	if (size > 0)
	{
		while (str2[i] && i < (size - 1))
		{
			str1[i] = str2[i];
			i++;
		}
		str1[i] = '\0';
	}
	return (ft_strlen(str2));
}

