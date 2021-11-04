#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (n < (size_t)start)
		return (ft_strdup(""));
	if (s[i] == '\0' && len > 1)
		len = 1;
	if (start + len > n)
		len = n - start;
	str = (char *) malloc(len + 1);
	if (!str)
		return (0);
	while (len > 0)
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = '\0';
	return (str);
}
