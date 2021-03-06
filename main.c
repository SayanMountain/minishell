#include "minishell.h"

void	print_list(t_list *g_cmd)
{
	int i;
	t_list	*tmp;

	tmp = g_cmd;
	while (tmp)
	{
		i = 0;
		while (tmp->cmd[i])
		{
			printf("|%s|\n", tmp->cmd[i]);
			i++;
		}
		tmp = tmp->next;
	}
}

static void ft_get_envp(t_msh *msh, char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	msh->g_env = malloc(sizeof(char *) * i + 1);
	i = -1;
	while (env[++i])
		msh->g_env[i] = ft_strdup(env[i]);
	msh->g_env[i] = NULL;
}

int main (int argc, char **argv, char **env)
{
	t_msh	msh;

    (void)argc;
    (void)argv;
    ft_get_envp(&msh, env);
	invitation(&msh);
//    signal(SIGINT, aft_sig_handle);
//    signal(SIGQUIT, ft_sig_handle);
//	exit(0);
//	printf("%s\n", msh.string_name);
    return (0);
}
