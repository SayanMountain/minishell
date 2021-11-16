#include "minishell.h"

void	rewriting_str(t_list *tmp, char *str, int j)
{
	free(tmp->cmd[j]);
	tmp->cmd[j] = NULL;
	tmp->cmd[j] = str;
}

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

int	skip_quotes(const char *str, int *i)
{
	if (str[*i] == '\"')
		while (str[++(*i)] != '\"')
			if (str[*i] == '\0')
			{
				error_msg(1, ' ');
				return (1);
			}
	if (str[*i] == '\'')
		while (str[++(*i)] != '\'')
			if (str[*i] == '\0')
			{
				error_msg(1, ' ');
				return (1);
			}
	return (0);
}

int	list_cmd(t_msh *msh)
{
	int		i;
	char	*tmp;
	t_list	*new;

	i = 0;
	msh->start = 0;
	msh->g_cmd = NULL;
	while (msh->string_name[i])
	{
		while (msh->string_name[i] != '|' && msh->string_name[i] != '\0')
		{
			if (check_char(msh->string_name[i], "'\""))
				if (skip_quotes(msh->string_name, &i))
					return (1);
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
	return (0);
}