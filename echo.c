#include "minishell.h"

static char *go_echo(char **env, char *key)
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

void	run_echo(t_msh *msh)
{
	char	*echo;

	if(!ft_strncmp(msh->string_name, "echo", ft_strlen("echo")))
	{
		echo = go_echo(&msh->string_name, "echo");
		echo = ft_substr(echo, 5, ft_strlen(msh->string_name) - 5);
		printf("%s\n", echo);
	}
	if(!ft_strncmp(msh->string_name, "echo -n", ft_strlen("echo -n")))
	{
		echo = go_echo(&msh->string_name, "echo -n");
		echo = ft_substr(echo, 8, ft_strlen(msh->string_name) - 8);
		ft_putstr_fd(echo, 1);
	}
}
