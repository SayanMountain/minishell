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

void	fill_key(t_list *g_env, const char *str, int *j)
{
	int	i;
	t_list	*tmp;

	i = 0;
	tmp = (t_list *)g_env->content;
	while (str[i] != '=')
		i++;
	(((t_env *)tmp->content)->key) = malloc(sizeof (char *) * (i + 1));
//	printf("%s\n", ((t_env *)tmp->content)->key);
	while (str[*j] != '=')
	{
		(((t_env *)tmp->content)->key)[*j] = str[*j];
		(*j)++;
	}
	(((t_env *)tmp->content)->key)[*j] = '\0';
//	printf("%s\n", ((t_env *)tmp->content)->value);
}

void	fill_value(t_list *g_env, char *str, int *i)
{
	int	j;
	size_t k;
	t_list	*tmp;

	j = 0;
	tmp = g_env;
	k = ft_strlen(str) - *i;
	((t_env *)tmp->content)->value = malloc(sizeof (char *) * (k + 1));
	while (str[*i])
	{
		((t_env *)tmp->content)->value[j] = str[*i];
		(*i)++;
		j++;
	}
	((t_env *)tmp->content)->value[j] = '\0';
}
