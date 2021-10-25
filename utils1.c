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

void	fill_key(t_list *g_env, int *j)
{
	int	i;
	t_list	*tmp;

	i = 0;
	tmp = g_env;
	while (((t_env *)tmp->content)->line_env[i] != '=')
		i++;
	((t_env *)tmp->content)->key = malloc(sizeof (char *) * (i + 1));
	while (((t_env *)tmp->content)->line_env[*j] != '=')
	{
		((t_env *)tmp->content)->key[*j] = ((t_env *)tmp->content)->line_env[*j];
		(*j)++;
	}
	((t_env *)tmp->content)->key[*j] = '\0';
}

void	fill_value(t_list *g_env, int *i)
{
	int	j;
	size_t k;
	t_list	*tmp;

	j = 0;
	tmp = g_env;
	k = ft_strlen(((t_env *)tmp->content)->line_env) - *i;
	((t_env *)tmp->content)->value = malloc(sizeof (char *) * (k + 1));
	while (((t_env *)tmp->content)->line_env[*i])
	{
		((t_env *)tmp->content)->value[j] = ((t_env *)tmp->content)->line_env[*i];
		(*i)++;
		j++;
	}
	((t_env *)tmp->content)->value[j] = '\0';
}