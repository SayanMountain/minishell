#include "minishell.h"

void run_export(t_msh *msh, t_list *tmp)
{
	t_env *new_list;

	if(ft_strchr(tmp->cmd[1], '='))
	{
		new_list = ft_lstnew_env(ft_strdup(tmp->cmd[1]));
		ft_lstadd_back_env(&msh->g_env, new_list);
	}
	if(tmp->cmd[2])
	{
		printf("export: `%s': not a valid identifier\n", tmp->cmd[2]);
	}
	if(tmp->cmd[3])
		printf("export: `%s': not a valid identifier\n", tmp->cmd[3]);

	printf("осталась сортировка по алфавиту\n");
}
