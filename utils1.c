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

void	hand_quotes(t_msh *msh, int *i)
{
	if (check_char(msh->string_name[*i], "\""))
		while (msh->string_name[++(*i)] != '"')
			;
	if (check_char(msh->string_name[*i], "'"))
		while (msh->string_name[++(*i)] != '\'')
			;
}

void	list_cmd(t_msh *msh)
{
	int i;
	char	*tmp;
	t_list	*new;
	t_cmd	*cmd;

	i = 0;
	msh->start = 0;
	cmd = NULL;
	while (msh->string_name[i])
	{
		while (check_char(msh->string_name[i], "|\0"))
		{
			if (check_char(msh->string_name[i], "'\""))
				hand_quotes(msh, &i);
			i++;
		}
		tmp = ft_substr(msh->string_name, msh->start, i - msh->start);
		new = ft_lstnew(cmd);
		((t_cmd *)new->content)->str = tmp;
		ft_lstadd_back(&msh->g_cmd, new);
		msh->start = i + 1;
	}
	tmp = ft_substr(msh->string_name, msh->start, i - msh->start);
	new = ft_lstnew(cmd);
	((t_cmd *)new->content)->str = tmp;
	ft_lstadd_back(&msh->g_cmd, new);
}
