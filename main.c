#include "minishell.h"

//строку из Переменной среды вложить в структуру

static void ft_get_envp(t_msh *msh, char **env)
{
	int	i;
	int j;
	t_list	*tmp;
	t_env 	*new;

	i = -1;
	while(env[++i])
	{
		new = ft_calloc(1, sizeof(t_env));
		new->line_env = env[i];
//		((t_env *)tmp->content)->line_env = env[i];
		tmp = ft_lstnew(new);
		ft_lstadd_back((msh->g_env->content), tmp);
	}
	tmp = (t_list *)msh->g_env;
	while (tmp)
	{
		j = 0;
		fill_key(tmp, &j);
		j++;
		fill_value(tmp, &j);
		tmp = (t_list *) tmp->next;
	}

//	tmp = (*msh).g_env;
//	((t_env *)tmp->content)->code = 10;
//	t_list *lst;
//
//	((t_cmd *)lst->line_env)->a;

//	i = 0;
//	tmp = g_env;
//	while (tmp)
//	{
//		printf("%s\n%s\n%s\n\n", tmp->line_env, tmp->key, tmp->value);
//		tmp = tmp->next;
//		i++;
//	}
}

//static void	ft_sig_handle(int signal)
//{
//	int	n;
//
//	if (signal == SIGINT)
//	{
////		printf("\b\b  \b\b");
//		printf("\n");
//		rl_on_new_line();
//		rl_replace_line("", 0);
//		rl_redisplay();
//	}
//	else if (signal == SIGQUIT)
//		printf("\b\b  \b\b");
//	wait(&n);
//	if (n == 2 || n == 3)
//	{
//		if (signal == 2)
//			ft_putchar_fd('\r', 1);
//		if (signal == 3)
//			ft_putendl_fd("Quit: 3", 1);
//	}
//}

int main (int argc, char **argv, char **env)
{
	int	i;
	t_msh msh;

	i = 0;
//	msh->g_env = NULL;
    (void)argc;
    (void)argv;
//    com_str = malloc(sizeof(char*) * argc);
    ft_get_envp(&msh, env);
//    signal(SIGINT, aft_sig_handle);
//    signal(SIGQUIT, ft_sig_handle);
	invitation(&msh);
	parser(&msh);
//	printf("%s\n", msh.string_name);
    return (0);
}
