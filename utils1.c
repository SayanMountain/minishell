#include "minishell.h"

//int ft_len_arr(char **arr)
//{
//	int i;
//
//	i = 0;
//	if(!arr)
//		return 0;
//	while(arr[i])
//		i++;
//	return (i);
//}

void	fill_key(t_list **g_env, int *j)
{
	int	i;
	t_list	*tmp;

	i = 0;
	tmp = *g_env;
	while (tmp->content[i] != '=')
		i++;
	tmp->key = malloc(sizeof (char *) * (i + 1));
	while (tmp->content[*j] != '=')
	{
		tmp->key[*j] = tmp->content[*j];
		(*j)++;
	}
	tmp->key[*j] = '\0';
}

void	fill_value(t_list **g_env, int i)
{
	int	j;
	size_t k;
	t_list	*tmp;

	j = 0;
	tmp = *g_env;
	k = ft_strlen(tmp->content) - (size_t)i;
	tmp->value = malloc(sizeof (char *) * (k + 1));
	while (tmp->content[i])
	{
		tmp->value[j] = tmp->content[i];
		i++;
		j++;
	}
	tmp->value[j] = '\0';
}