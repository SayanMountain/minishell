#include "minishell.h"

char	*join_str(t_msh *msh, char *str, int *i)
{
	int k;
	char	*str1;
	char	*str2;
	char	*str3;

	k = *i;

	skip_quotes(msh, str, i);
	str1 = ft_substr(str, 0, k);
	str2 = ft_substr(str, k + 1, *i - k - 1);
	str3 = ft_strdup(str + *i + 1);
	str1 = ft_strjoin(str1, str2);
	str1 = ft_strjoin(str1, str3);
	return (str1);
}

void	remove_quotes(t_msh *msh)
{
	int	j;
	int i;
	char	*str;
	t_list	*tmp;

	tmp = msh->g_cmd;
	while (tmp)
	{
		j = 0;
		while (tmp->cmd[j])
		{
			i = -1;
			while (tmp->cmd[j][++i])
				if (check_char(tmp->cmd[j][i], "\'\""))
				{
					str = join_str(msh, tmp->cmd[j], &i);
					rewriting_str(tmp, str, j);
				}
			j++;
		}
		tmp = tmp->next;
	}
}

void	write_arr(t_msh *msh, t_list *tmp, int *i)
{
	int		k;
	char	**new_arr;
	char	*new_str;

	k = -1;
	new_arr = (char **)malloc(sizeof(char *) * (msh->len_arr + 2));
	if (!new_arr)
		return;
	while (++k < msh->len_arr)
		new_arr[k] = tmp->cmd[k];
	new_str = ft_substr(tmp->str, msh->start, (*i) - msh->start);
	new_arr[msh->len_arr] = new_str;
	new_arr[msh->len_arr + 1] = NULL;
	tmp->cmd = new_arr;
	msh->len_arr++;
}

int 	split_str(t_msh *msh, t_list *tmp)
{
	int		i;

	i = 0;
	while (tmp->str[i])
	{
		check_space(msh, tmp->str, &i);
		while (tmp->str[i] != '\0' && tmp->str[i] != ' ')
		{
			if (check_char(tmp->str[i], "\'\""))
			{
				skip_quotes(msh, tmp->str, &i);
//				printf("%s\n", msh->val_baks);
				return (1);
			}
			if (check_baks(msh, tmp->str, &i))
				return (1);
			i++;
		}
		write_arr(msh, tmp, &i);
		check_space(msh, tmp->str, &i);
	}
	return (0);
}

int 	split_str_cmd(t_msh *msh)
{
	t_list	*tmp;

	if (msh->g_cmd)
		msh->g_cmd->cmd = NULL;
	tmp = msh->g_cmd;
	while (tmp)
	{
		msh->len_arr = 0;
		msh->start = 0;
		if (split_str(msh, tmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

