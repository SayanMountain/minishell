#include "minishell.h"

//строку из Переменной среды вложить в структуру

static void ft_get_envp(t_list **g_env, char **env)
{
	int	i;
	int j;
	t_list	*tmp;

	i = -1;
	while(env[++i])
	{

		tmp = ft_lstnew(env[i]);
		ft_lstadd_back(g_env, tmp);
	}
	tmp = *g_env;
	while (tmp)
	{
		j = 0;
		fill_key(&tmp, &j);
		j++;
		fill_value(&tmp, j);
		tmp = tmp->next;
	}

//	i = 0;
//	tmp = g_env;
//	while (tmp)
//	{
//		printf("%s\n%s\n%s\n\n", tmp->content, tmp->key, tmp->value);
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
	t_list	*g_env;

	i = 0;
	g_env  = NULL;
    (void)argc;
    (void)argv;
    ft_get_envp(&g_env, env);
//    signal(SIGINT, aft_sig_handle);
//    signal(SIGQUIT, ft_sig_handle);
	invitation(&g_env);
	parser(argc, argv);
    return (0);
}
