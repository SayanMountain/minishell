#include "minishell.h"

static char	*go_env(t_env *env, char *key)
{
	while (env)
	{
		if (!ft_strncmp(env->str, key, ft_strlen(key)))
		{
			return (env->str);
		}
		env = env->next;
	}
	return (NULL);
}

static void	ft_lstdelone(t_env *start, t_env *del)
{
	t_env	*tmp;
	t_env	*env;
	int		i;

	i = 0;
	if (!del)
		return ;
	env = start;
	while (env)
	{
		if (env->next == del)
			break ;
		env = env->next;
		i++;
	}
	if (env == NULL)
		return ;
	tmp = del->next;
	free(del->str);
	free(del);
	env->next = tmp;
}

void	run_unset(t_msh *msh, t_list *tmp)
{
	t_env		*list_unset;
	char		*str;
	char		*del_list;

	list_unset = msh->g_env;
	str = tmp->cmd[1];
	del_list = go_env(msh->g_env, str);
	while (list_unset)
	{
		if (!ft_strcmp(list_unset->str, str))
			ft_lstdelone(msh->g_env, list_unset);
		list_unset = list_unset->next;
	}
}
