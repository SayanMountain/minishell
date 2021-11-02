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

//void	create_list(t_msh *msh)
//{
//
//}

void	hand_quotes(t_msh *msh, int *i)
{
//	int	j;
//	char	*tmp2;
//	char	*tmp3;

	if (check_char(msh->string_name[*i], "\""))
		while (msh->string_name[++(*i)] != '"')
			;
	if (check_char(msh->string_name[*i], "'"))
		while (msh->string_name[++(*i)] != '\'')
			;
//	tmp2 = ft_substr(msh->string_name, j + 1, *i - j - 1);
//	tmp3 = ft_strdup(msh->string_name + (*i) + 1);
//	tmp1 = ft_strjoin(tmp1, tmp2);
//	tmp1 = ft_strjoin(tmp1, tmp3);
//	msh->qwerty = tmp1;
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
//			else if (check_char(msh->string_name[i], "|\n"))
//				create_list(msh);
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
//	printf("%s\n", msh->qwerty);
}



//char	**strarr_add(char **arr, size_t arrlen, char *new)
//{
//	char	**new_arr;
//
//
//	new_arr = (char	**)check_malloc(ft_calloc(arrlen + 2, sizeof(char *)));
//	if (!new_arr || !new)
//		return (NULL);
//	if (arrlen >= 1 && arr)
//		ft_memcpy(new_arr, arr, sizeof(char *) * (arrlen + 1));
//	new_arr[arrlen] = new;
//	new_arr[arrlen + 1] = NULL;
//	if (arr)
//		free(arr);
//	return (new_arr);
//}