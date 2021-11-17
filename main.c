#include "minishell.h"

void	print_list(t_list *g_cmd)
{
	int i;
	t_list	*tmp;

	tmp = g_cmd;
	while (tmp)
	{
		i = 0;
		printf("Начало массива ->\n");
		while (tmp->cmd[i])
		{
			printf("|%s|\n", tmp->cmd[i]);
			i++;
		}
		printf("Конец массива <-\n");
		tmp = tmp->next;
	}
}



static void ft_get_envp(t_msh *msh, char **env)
{
	int		i;
	t_env	*new;

	msh->g_env = NULL;
	i = -1;
	while (env[++i])
	{
		new = ft_lstnew_env(ft_strdup(env[i]));
		ft_lstadd_back_env(&msh->g_env, new);
//		free(str);
	}
	i = 0;
	while (env[i])
		i++;
	msh->a_env = malloc(sizeof(char *) * i + 1);
	i = -1;
	while (env[++i])
		msh->a_env[i] = ft_strdup(env[i]);
	msh->a_env[i] = NULL;

//	t_env *tmp;
//	tmp = msh->g_env;
//	while (tmp)
//	{
////		printf("%s\n", tmp->str);
//		tmp = tmp->next;
//	}
}

int main (int argc, char **argv, char **env)
{
	t_msh	msh;

	g_status = 0;
    (void)argc;
    (void)argv;
    ft_get_envp(&msh, env);
	invitation(&msh);

//    signal(SIGINT, aft_sig_handle);
//    signal(SIGQUIT, ft_sig_handle);
//	exit(0);
    return (0);
}
