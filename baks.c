#include "minishell.h"

char	*value(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '=');
	return (ft_strdup(&str[++i]));
}

int		check_baks(t_msh *msh, char *str, int *i)
{
	char	*value;

	value = NULL;
	if (str[*i] == '$')
	{
		value = baks(msh, str, i);
		printf("%s\n", value);
		return (1);
	}
	return (0);
}

char	*baks(t_msh *msh, char *str, int *i)
{
	char	*s;
	int		j;
	int		k;

	j = ++(*i);
//	if (*i == '?')
//		return (g_status);
	while (str[*i] && str[*i] != ' ' && str[*i] != '\"')
		(*i)++;
	s = ft_substr(str, j, *i - j);
	k = -1;
	while (msh->a_env[++k])
		if (!ft_strncmp(msh->a_env[k], s, ft_strlen(s)))
			return (value(msh->a_env[k]));
	return (0);
}