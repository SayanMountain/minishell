#include "minishell.h"

//строку из Переменной среды вложить в структуру

static void ft_get_envp (char **env)
{
	int	i;
	int j;
	t_list	*tmp;
	t_list	*g_env;

	g_env  = NULL;
	i = -1;
//	g_env = (t_env){0};
//	g_env.envp = malloc(sizeof(char *) * ft_len_arr(env) + 1);

	while(env[++i])
	{

		tmp = ft_lstnew(env[i]);
		ft_lstadd_back(&g_env, tmp);
	}
	printf("%s", g_env->content);
	tmp = g_env;

	while (tmp)
	{
		j = 0;
		fill_key(tmp);
		i++;
		fill_value(tmp, i);
		tmp = tmp->next;
	}
//	i = 0;
//	while (g_env->content[i])
//		printf("%s\t%s\t%s", g_env->content, g_env->key, g_env->value);
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

	i = 0;
    (void)argc;
    (void)argv;
    ft_get_envp(env);
//    signal(SIGINT, ft_sig_handle);
//    signal(SIGQUIT, ft_sig_handle);
//	invitation();
//	while (argv[++i])
//		parser(argv[i]);
    return (0);
}
