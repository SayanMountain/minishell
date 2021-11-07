#include "minishell.h"

int	check_char(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	skip_quotes(const char *str, int *i)
{
	if (str[*i] == '\"')
		while (str[++(*i)] != '\"')
			;
	else if (str[*i] == '\'')
		while (str[++(*i)] != '\'')
			;
}

void	list_cmd(t_msh *msh)
{
	int		i;
	char	*tmp;
	t_list	*new;

	i = 0;
	msh->start = 0;

	while (msh->string_name[i])
	{
		while (msh->string_name[i] != '|' && msh->string_name[i] != '\0')
		{
			if (check_char(msh->string_name[i], "'\""))
				skip_quotes(msh->string_name, &i);
			i++;
		}
		tmp = ft_substr(msh->string_name, msh->start, i - msh->start);
		new = ft_lstnew(tmp);
		ft_lstadd_back(&msh->g_cmd, new);
		msh->start = i + 1;
		while ((msh->string_name[i] == '|' || msh->string_name[i] == ' ') &&
			msh->string_name[i])
			i++;
	}
}