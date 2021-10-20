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

void	fill_key(t_list *tmp)
{
	int	i;

	i = 0;
	while (tmp->content[i] != '=')
		i++;
	tmp->key = malloc(sizeof (char *) * i);
	i = 0;
	while (tmp->content[i] != '=')
	{
		tmp->key[i] = tmp->content[i];
		i++;
	}
}

void	fill_value(t_list *tmp, int i)
{
	int	j;
	size_t k;

	j = 0;
	k = ft_strlen(tmp->content) - (size_t)i;
	tmp->value = malloc(sizeof (char *) * k);
	while (tmp->content[i])
	{
		tmp->value[j] = tmp->content[i];
		i++;
		j++;
	}
}