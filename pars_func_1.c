#include "minishell.h"

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
	free(tmp->cmd);
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

//void	write_arr_2(t_msh *msh, char *str)
//{
//	int		k;
//	char	**new_arr;
//
//	k = -1;
//	new_arr = (char **)malloc(sizeof(char *) * (msh->len_arr + 2));
//	if (!new_arr)
//		return;
//	while (++k < msh->len_arr)
//		new_arr[k] = msh->g_cmd->cmd[k];
//	new_arr[msh->len_arr] = str;
//	new_arr[msh->len_arr + 1] = NULL;
//	//	free(old_arr);
//	msh->g_cmd->cmd = new_arr;
//}

//char	*remove_quotes(t_msh *msh, t_list *tmp, int *i)
//{
//	int j;
//	char	*str1;
//	char	*str2;
//	char	*str3;
//
//	j = *i;
//	hand_quotes(tmp->str, i);
//	str1 = ft_substr(tmp->str, 0, j - 1);
//	str2 = ft_substr(tmp->str, j + 1, *i - j - 1);
//	j = *i;
//	while (tmp->str[(*i) + 1] != ' ')
//		(*i)++;
//	str3 = ft_substr(tmp->str, j + 1, *i - j);
//	str1 = ft_strjoin(str1, str2);
//	str1 = ft_strjoin(str1, str3);
//	return (str1);
//}
