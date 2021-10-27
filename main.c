#include "minishell.h"

//строку из Переменной среды вложить в структуру

static void ft_get_envp(t_msh *msh, char **env)
{
	int i;
	int j;
	t_list *tmp;
	t_env  *new;

	i = 0;
	msh->g_env = NULL;
	while(env[i])
	{
		new = ft_calloc(1, sizeof(t_env));
//		fill_line_env(env[i], new);
		//printf("env[%d] %s len=%zu \n", i, env[i], ft_strlen(env[i]));
		new->line_env = ft_strdup(env[i]);
		j = fill_key(new, new->line_env);
		char *str= ft_strdup(new->line_env + ++j);
		new->value = str;
		tmp = ft_lstnew(new);
		ft_lstadd_back(&(msh->g_env), tmp);
//		printf("%s\n", ((t_env *)tmp->content)->line_env);
		i++;
	}
//	printf("end\n");
//	tmp = msh->g_env;
//	while (tmp)
//	{
//		printf("%s\n", ((t_env *)tmp->content)->line_env);
//		tmp = tmp->next;
//	}
//	exit(0);
//	printf("START\n");
//char *str_tmp;
//	while (tmp)
//	{
////		printf(" %s\n", ((t_env *)tmp->content)->line_env);
//
//		j = 0;
//		fill_key(tmp, ((t_env *) tmp->content)->line_env);
//		j++;
//		str_tmp = ft_strdup(((t_env *)tmp->content)->line_env);
////		printf("STAR1T\n");
////		fill_value(tmp, ((t_env *)tmp->content)->line_env, &j);
//		char *str= ft_strdup(((t_env *)tmp->content)->line_env + j);
//		((t_env *)tmp->content)->value = str;
//		((t_env *)tmp->content)->line_env = str_tmp;
//
////		printf("STAR2T\n");
//		tmp = tmp->next;
//	}
//	printf("END\n");
//	exit(0);
	i = 0;
//	new = msh->g_env->content;
	tmp = msh->g_env;
	while (tmp)
	{
		new = tmp->content;
		printf("%s\n%s\n%s\n\n", new->line_env, new->key, new->value);
		tmp = tmp->next;
	}
}

//	tmp = (*msh).g_env;
//	((t_env *)tmp->content)->code = 10;
//	t_list *lst;
//
//	((t_cmd *)lst->line_env)->a;

// }

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
	msh.g_env = NULL;
    (void)argc;
    (void)argv;
//    com_str = malloc(sizeof(char*) * argc);
    ft_get_envp(&msh, env);
//    signal(SIGINT, aft_sig_handle);
//    signal(SIGQUIT, ft_sig_handle);
	exit(0);
	invitation(&msh);
	parser(&msh);
//	printf("%s\n", msh.string_name);
    return (0);
}
