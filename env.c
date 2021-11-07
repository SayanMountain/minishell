#include "minishell.h"

void run_env(t_msh *msh)
{
	int i = 0;

	while(msh->g_env[i])
	{
		printf("%s\n", msh->g_env[i]);
		i++;
	}
}

void not_found(t_msh *msh)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(msh->string_name, ": command not found\n");
	tmp2 = ft_strjoin("minishell: ", tmp1);
	ft_putstr_fd(ft_strjoin(tmp1, tmp2), 1);
}
