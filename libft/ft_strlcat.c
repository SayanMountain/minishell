#include "libft.h"

size_t	ft_strlcat(char *str1, const char *str2, size_t size)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (size <= len1)
		len2 += size;
	else
		len2 += len1;
	if (len1 < (size - 1) && size > 0)
	{
		while (str2[i] && i < (size - (len2 - ft_strlen(str2)) - 1))
		{
			str1[len1] = str2[i];
			len1++;
			i++;
		}
		str1[len1] = '\0';
	}
	return (len2);
}
