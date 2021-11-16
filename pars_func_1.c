#include "minishell.h"

char	*join_str(char *str, int *i)
{
	int k;
	char	*str1;
	char	*str2;
	char	*str3;

	k = *i;

	skip_quotes(str, i);
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
					str = join_str(tmp->cmd[j], &i);
					rewriting_str(tmp, str, j);
				}
			j++;
		}
		tmp = tmp->next;
	}
}

void	check_space(t_msh *msh, t_list *tmp, int *i)
{
	while (tmp->str[*i] && tmp->str[*i] == ' ')
		(*i)++;
	msh->start = *i;
}

void	write_arr(t_msh *msh, t_list *tmp, int i)
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
	new_str = ft_substr(tmp->str, msh->start, i - msh->start);
	new_arr[msh->len_arr] = new_str;
	new_arr[msh->len_arr + 1] = NULL;
//	free(tmp->cmd);
	tmp->cmd = new_arr;
	msh->len_arr++;
}

void	split_str_cmd(t_msh *msh)
{
	int		i;
	t_list	*tmp;

	msh->g_cmd->cmd = NULL;
	tmp = msh->g_cmd;
	while (tmp)
	{
		i = 0;
		msh->len_arr = 0;
		msh->start = 0;
		while (tmp->str[i])
		{
			check_space(msh, tmp, &i);
			while (tmp->str[i] != '\0' && tmp->str[i] != ' ')
			{
				if (check_char(tmp->str[i], "\'\""))
					skip_quotes(tmp->str, &i);
				i++;
			}
			write_arr(msh, tmp, i);
			check_space(msh, tmp, &i);
		}
		tmp = tmp->next;
	}
}

