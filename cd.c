#include "minishell.h"

static char *go_env(char **env, char *key)
{
	int i = 0;
	while(env[i])
	{
		if (!ft_strncmp(env[i], key, ft_strlen(key)))
		{
			return (env[i]);
		}
		i++;
	}
	return(NULL);
}

void cd(t_msh *msh)
{
	char 	*path;
	int 	i = 0;

		if(!ft_strncmp(msh->string_name, "cd ~", ft_strlen("cd ~")))
		{
				path = go_env(msh->g_env, "HOME");
				path = ft_substr(path, 5, ft_strlen(msh->g_env[i]) - 5);
		}
		if(!ft_strncmp(msh->string_name, "cd -", ft_strlen("cd -")))
		{
			path = go_env(msh->g_env, "OLDPWD");
			path = ft_substr(path, 7, ft_strlen(msh->g_env[i]) - 7);
			printf("%s\n", path);
		}
		if(!ft_strncmp(msh->string_name, "cd", ft_strlen("cd")))
		{
			path = go_env(msh->g_env, "HOME");
			path = ft_substr(path, 5, ft_strlen(msh->g_env[i]) - 5);
		}
		chdir(path);
}
