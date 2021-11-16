#include "minishell.h"

static char *go_env(t_env *env, char *key)
{
	while(env)
	{
		if (!ft_strncmp(env->str, key, ft_strlen(key)))
		{
			return (env->str);
		}
		env = env->next;
	}
	return(NULL);
}

static int count_cmd_len(t_msh *msh)
{
	char 	**tmp;
	int i = 0;

	tmp = msh->g_cmd->cmd;
	while(tmp[i])
		i++;
	return i;
}

void run_cd_standart(t_msh *msh)
{
	char 	*path;
	t_list *tmp;

	tmp = msh->g_cmd;

	if(count_cmd_len(msh) == 1 || !ft_strncmp(tmp->cmd[1], "~", ft_strlen("~")))
	{
			path = go_env(msh->g_env, "HOME");
			path = ft_substr(path, 5, ft_strlen(path) - 5);
	} else
		path = tmp->cmd[1];
	if(count_cmd_len(msh) == 1 || !ft_strncmp(tmp->cmd[1], "-", ft_strlen("-")))
	{
		path = go_env(msh->g_env, "OLDPWD");
		path = ft_substr(path, 5, ft_strlen(path) - 5);
	}
	chdir(path);

	printf("не меняет OLDPWD\n");
	printf("руками поменять OLDPWD\n");
}
