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

void	fill_line_env(char *env, t_env *new)
{
	int	i;
	size_t len;

	i = 0;
	len = ft_strlen(env);

	//printf("len =%zu\n", len);

	new->line_env = ft_strdup(env);
//	while (env[i])
//	{
//		new->line_env[i] = env[i];
//		i++;
//	}
//	new->line_env[i] = '\0';
	//printf("AAAAAAAAA\n");
}

int fill_key(t_env *g_env, const char *str)
{
	int	i;
//	t_env	*tmp;

	i = 0;
//	tmp = g_env->content;
	while (str[i] && str[i] != '=')
		i++;
	(g_env->key) = malloc(sizeof (char) * (i + 1));
	ft_strlcpy(g_env->key, str, i + 1);
	return i;
//	printf("%s\n", ((t_env *)tmp->content)->key);
//	while (str[*j] && str[*j] != '=')
//	{
//		(tmp)->key[*j] = str[*j];
//		(*j)++;
//	}
//	(tmp)->key[*j] = '\0';
//	printf("%s\n", ((t_env *)tmp->content)->key);
}

void	fill_value(t_list *g_env, char *str, int *i)
{
//	printf("i= %d\n", *i);

	int	j;
	size_t k;
	t_list	*tmp;

	j = 0;
	tmp = g_env;

//	printf("s= %s\n", (str));
//	printf("strlen= %zu\n", ft_strlen(str));

	k = ft_strlen(str) - *i;

//	printf("k= %zu\n", k);

	((t_env *)(g_env->content))->value = ft_strdup(str + *i);

//	(((t_env *)tmp->content)->value) = malloc(sizeof (char) * (k + 1));
	//printf("%lu - %s", k, str);
//	exit(0);
//	printf("111\n");
//	while (str[*i])
//	{
//		(((t_env *)tmp->content)->value)[j] = str[*i];
//		(*i)++;
//		j++;
//	}
//	(((t_env *)tmp->content)->value)[j] = '\0';
}
