#include "minishell.h"

void	write_arr(t_msh *msh, t_list *tmp, int len_arr, int i)
{
	int		k;
	char	**new_arr;
//	char	**old_arr;
	char	*new_str;

	k = -1;
//	old_arr = tmp->cmd;
	new_arr = (char **)malloc(sizeof(char *) * (len_arr + 2));
	if (!new_arr)
		return;
	while (++k < len_arr)
		new_arr[k] = tmp->cmd[k];
	new_str = ft_substr(tmp->content, msh->start, i);
	new_arr[len_arr] = new_str;
	new_arr[len_arr + 1] = NULL;
//	free(old_arr);
	tmp->cmd = new_arr;
}

void	split_str_cmd(t_msh *msh)
{
	int		i;
	int		len_arr;
	t_list	*tmp;

	tmp = msh->g_cmd;
	while (tmp)
	{
		i = 0;
		len_arr = 0;
		msh->start = 0;
		while (tmp->content[i])
		{
			while (!check_char(tmp->content[i], " '\"") && tmp->content[i] !=
			'\0')
				i++;
			if (check_char(tmp->content[i], "'\""))
				hand_quotes(tmp->content, &i);
			write_arr(msh, tmp, len_arr, i);
			len_arr++;
			i++;
			msh->start = i;
		}
		tmp = tmp->next;
	}
}